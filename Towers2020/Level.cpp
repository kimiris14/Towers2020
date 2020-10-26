/**
* \file Level.cpp
*
* \author PaulaRed
*
* Class that represents a level
*/

#include "pch.h"
#include "Level.h"
#include "Game.h"
#include "GamePallette.h"
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include "ItemVisitor.h"
#include "ItemVisitorFindRoad.h"
#include "ItemVisitorFindTile.h"
#include "ItemVisitorFindTower.h"
#include "TowerOwen.h"
#include "ItemBalloon.h"
#include "ItemBalloonGhost.h"
#include "Tower.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/// The directory where all of the images are stored. Be sure to include a trailing "/"
const wstring ImagesDirectory = L"images/";


/**
* Constructor
* \param game The game object that this level belongs to
* \param filename The filename of the XML level definition file for this level
*/
CLevel::CLevel(CGame* game, std::wstring filename) : mGame(game) 
{
    // grab the level number from the filename
    mLevelNumber = filename[12];
    Load(filename);

}



/// This function is called by a road tile when a baloon has exited the game.
/// This means that points are lost.
/// \param balloon The shared pointer to the escaped balloon
void CLevel::EscapedBalloon(std::shared_ptr<CItemBalloon> balloon)
{
    mItemsToDelete.push_back(balloon);

    // be absolutely certain that the balloon isn't popped before we decrement the score
    if (balloon->IsActive())
    {
        balloon->SetActive(false);
        mGame->GetPallette()->DecrementScore(mPointsPerEscape);
        // decrease number of active balloons if balloons escape
        this->DerementActiveBalloons();

    }
}

/// This searches the playing area for a clicked tower. If a tower object was
/// found, that object is returned.
/// \param x The x coordinate in pixels
/// \param y the y coordinate in pixels
/// \returns A pointer to the clicked tower if found
CTower* CLevel::PickUpTower(int x, int y)
{
    // this only finds towers
    CItemVisitorFindTower visitor(x, y);
    Accept(&visitor);
    CTower* tower = visitor.GetTower();


    // if there was a tower that was found and clicked on, pick it up and return it
    if ((tower != nullptr)) 
    {

        auto x = (int)tower->GetX();
        auto y = (int)tower->GetY();

        int gridX = x / mTileSpacing;
        int gridY = y / mTileSpacing;

        // find the tile on this grid.
        CItemVisitorFindTile visitor(gridX, gridY);
        Accept(&visitor);
        auto currentTile = visitor.GetTile();

        // "pick up" the tile
        if (currentTile != nullptr)
        {
            currentTile->SetOpen(true);
        }

        return tower;
    }

    return nullptr;
}


/// Runs a hit test on all of the items in the level, and returns the
/// last item that was hit (the last item in the mItems list)
/// \param x The x pixel to search for
/// \param y The y pixel to search for
/// \returns a shared ptr to the found object
std::shared_ptr<CItem> CLevel::HitTest(int x, int y)
{
    shared_ptr<CItem> lastItem = nullptr;
    for (auto item : mItems)
    {
        if (item->HitTest(x, y))
        {
            lastItem = item;
        }
    }
    return lastItem;

}


/// Spawns a ghost at random
void CLevel::SpawnGhost()
{

    double spawnProb = ((double)rand() / RAND_MAX);
    if (spawnProb <= mGhostProbability)
    {
        /// Spawn at a random x value along the width of the game
        double spawnX = ((double)rand() / RAND_MAX) * (CGame::Width - CGamePallette::PaletteWidth);

        auto ghost = make_shared<CItemBalloonGhost>(this, mGame);
        ghost->SetLocation(spawnX, CGame::Height);

        AddDeferred(ghost);

    }
}


/**
 * Load the game level from a .xml file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the level from.
 */
void CLevel::Load(std::wstring filename)
{

    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Get the basic level configuration information

        mLevelWidth = root->GetAttributeIntValue(L"width", 0);
        mLevelHeight = root->GetAttributeIntValue(L"height", 0);
        mStartingX = root->GetAttributeIntValue(L"start-x", 0);
        mStartingY = root->GetAttributeIntValue(L"start-y", 0);


        // Once we know it is open, clear the existing data
        Clear();

        // Traverse the children of the root
        // node of the XML document in memory!!!!
        for (auto node : root->GetChildren())
        {

            // this is where we get the items
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"declarations")
            {
                for (auto declNode : node->GetChildren())
                {
                    // loads all of the associated images
                    XmlItemDeclaration(declNode);
                }
            }

            // this is where we get the items
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"items")
            {
                for (auto itemNode : node->GetChildren())
                {
                    XmlItem(itemNode);
                }
            }
        }

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }


    // at this point, all of the tiles are loaded in. We can construct the path
    int currentX = mStartingX;
    int currentY = mStartingY;

    // to find the starting tile
    CItemVisitorFindRoad visitor1(currentX, currentY);
    Accept(&visitor1);
    CItemTileRoad* prevRoad = visitor1.GetRoad();
    CItemTileRoad* currRoad = nullptr;

    // if the starting tile is not an east to west tile, that means it must be in reverse.
    // For example, it could be a north to east tile, or a south to east
    if ((prevRoad->GetType() == L"NE") || (prevRoad->GetType() == L"SE") || (prevRoad->GetType() == L"EW"))
        prevRoad->SetReversedDirection(true);

    while (prevRoad != nullptr)
    {
        wstring prevType = prevRoad->GetType();

        // these booleans will tell us where to save the next road in the current road
        bool newNorth = false;
        bool newEast = false;
        bool newSouth = false;
        bool newWest = false;

        // next tile should be north (up one index)
        if (((prevType == L"NS") && (prevRoad->IsReversed())) ||
            ((prevType == L"NE") && (prevRoad->IsReversed())) ||
            ((prevType == L"NW") && (prevRoad->IsReversed())))
        {
            currentY--;  // remember that in computer-land, pixels are from the top left, down
            newNorth = true;
        }

        // next tile should be south (down one index)
        else if (((prevType == L"NS") && (!prevRoad->IsReversed())) ||
            ((prevType == L"SE") && (prevRoad->IsReversed())) ||
            ((prevType == L"SW") && (prevRoad->IsReversed())))
        {
            currentY++;  // remember that in computer-land, pixels are from the top left, down
            newSouth = true;
        }

        // the next tile should be to the east (right one index)
        else if (((prevType == L"EW") && (prevRoad->IsReversed())) ||
            ((prevType == L"SE") && (!prevRoad->IsReversed())) ||
            ((prevType == L"NE") && (!prevRoad->IsReversed())))
        {
            currentX++;
            newEast = true;
        }

        // the next tile should be to the west (left one index)
        else if (((prevType == L"EW") && (!prevRoad->IsReversed())) ||
            ((prevType == L"SW") && (!prevRoad->IsReversed())) ||
            ((prevType == L"NW") && (!prevRoad->IsReversed())))
        {
            currentX--;
            newWest = true;
        }


        // Now we know where to expect the next road tile. Attempt to find it with a visitor
        CItemVisitorFindRoad visitor2(currentX, currentY);
        Accept(&visitor2);
        currRoad = visitor2.GetRoad();

        // important to wrap everything here in a nullptr block, since there's a chance that
        // there was no tile found
        if (currRoad != nullptr)
        {
            // we found the next road! Let's be sure to tell the previous road where the balloons
            // should be going next
            if (newNorth)
            {
                prevRoad->SetNextNorth(currRoad);

                // we're going north and entering from the south side, so the next tile is reversed if...
                if ((currRoad->GetType() == L"NS"))
                    currRoad->SetReversedDirection(true);
            }
            else if (newSouth)
            {
                prevRoad->SetNextSouth(currRoad);

                // we're going south and entering from the north side, so the next is never reversed, because
                // all tiles with North in them start with North ("NS" "NW" "NE")
            }
            else if (newEast)
            {
                prevRoad->SetNextEast(currRoad);

                // we're going east and entering from the west side, so the next tile is reversed if...
                if ((currRoad->GetType() == L"NW") || (currRoad->GetType() == L"SW") || (currRoad->GetType() == L"EW"))
                    currRoad->SetReversedDirection(true);
            }
            else if (newWest)
            {
                prevRoad->SetNextWest(currRoad);

                // we're going east and entering from the east side, so the next tile is reversed if...
                if ((currRoad->GetType() == L"NE") || (currRoad->GetType() == L"SE"))
                    currRoad->SetReversedDirection(true);
            }

        }

        // update the road for the next iteration
        prevRoad = currRoad;
    }

}

/**
 * Clear the game data.
 *
 * Deletes all known items in the game.
 */
void CLevel::Clear()
{
    mItems.clear();
}




/**
 * Draws all of the items in this level
 * \param graphics The graphics context to draw on
 */
void CLevel::Draw(Gdiplus::Graphics* graphics)
{
    for (auto item : mItems) 
    {
        item->Draw(graphics);
    }

    // Draw the level title
    if (mDisplayTitle && mLevelNumber != L"3")
    {
        //Font 
        FontFamily fontFamily(L"Arial");

        //Font size for title
        Gdiplus::Font font(&fontFamily, LevelTextSizeSmall, FontStyleBold, UnitPixel);

        //Draw the title in brown
        SolidBrush color(Color::Brown);

        wstring levelw;
        if (mLevelCompleted == false)
            levelw = L"Level " + mLevelNumber + L" Begin";
        if (mLevelCompleted == true)
            levelw = L"Level Complete!";
        graphics->DrawString(levelw.c_str(),  // String to draw
            -1,         // String length, -1 so it figures it out on its own
            &font,      // The font to use
            PointF(LevelStringX, LevelTitleY),   // Draw to the center of the game palette
            &color);    // The brush to draw the text with
    }

    // Draw the level title
    if (mDisplayTitle && mLevelNumber == L"3")
    {
        //Font 
        FontFamily fontFamily(L"Chiller");

        //Font size for title
        Gdiplus::Font font(&fontFamily, LevelTextSizeLarge, FontStyleBold, UnitPixel);

        //Draw the title in brown
        SolidBrush color(Color(215, 55, 5));

        wstring levelw;
        if (mLevelCompleted == false)
            levelw = L"Level " + mLevelNumber + L" Begin";
        if (mLevelCompleted == true)
            levelw = L"Level Complete!";
        graphics->DrawString(levelw.c_str(),  // String to draw
            -1,         // String length, -1 so it figures it out on its own
            &font,      // The font to use
            PointF(LevelStringX, LevelTitleY),   // Draw to the center of the game palette
            &color);    // The brush to draw the text with
    }

}


/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{

    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    wstring type = node->GetName();

    // Get the image ID attribute value
    auto imageIDString = node->GetAttributeValue(L"id", L"");
    int imageID = stoi(imageIDString.substr(1));  // removes the leading "i"


    if (type == L"open")
    {
        auto itemOccupied = make_shared<CItemTile>(this, mGame, imageID);
        itemOccupied->SetOpen(true);
        item = itemOccupied;
    }

    if ((type == L"trees") || (type == L"house"))
    {
        auto itemOccupied = make_shared<CItemTile>(this, mGame, imageID);
        itemOccupied->SetOpen(false);
        item = itemOccupied;

    }

    if (type == L"road")
    {
        item = make_shared<CItemTileRoad>(this, mGame, imageID, mIDToRoad[imageID]);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);

        Add(item);
    }

}


/**
 * Takes an item declaration node from the XML file and loads it into the image map
 * \param node The declaration node to process
 */
void CLevel::XmlItemDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // Get the image ID attribute value
    auto imageIDString = node->GetAttributeValue(L"id", L"");
    int imageID = stoi(imageIDString.substr(1));  // removes the leading "i"

    wstring imageFile = ImagesDirectory + node->GetAttributeValue(L"image", L"");

    // add the image to the game
    mGame->AddImage(imageID, imageFile);

    // save the road type to the ID map
    mIDToRoad[imageID] = node->GetAttributeValue(L"type", L"");
}


/**
* Add an item to the level
* \param item The item we are adding
*/
void CLevel::Add(shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
* Safely add an item to the level by inserting it into the mDeferredAdds list
* \param item The item we are adding
*/
void CLevel::AddDeferred(std::shared_ptr<CItem> item)
{
    mDeferredAdds.push_back(item);
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CLevel::Update(double elapsed)
{
    mTotalElapsedTime = mTotalElapsedTime + elapsed;

    // if 2 seconds have passed, get rid of the level title display
    if (mTotalElapsedTime > mDisplayTitleTime && mDisplayTitle == true && mLevelCompleted == false)
    {
        // reset total elapsed time so now the total elapsed time keeps track of total play time
        mDisplayTitle = false;
        mTotalElapsedTime = 0;
    }

    // if there are no more active balloons the level is completed
    if (mNumBalloonsActive == 0) 
    {
        // the level is complete (redundancy?)
        mDisplayTitle = true;
        mLevelCompleted = true;
        mLevelActive = false;

        // reset the elapsed time only if we havent already
        if (mResetTotalElapsedTime == false)
        {
            mTotalElapsedTime = 0;
            mResetTotalElapsedTime = true;
        }

        // check if 2 seconds has passed since we completed the level
        if (mTotalElapsedTime > mDisplayTitleTime && mLevelCompleted == true)
        {
            // figure out the next level to load
            // if the current level is not the last level, the next level will be this level + 1
            if (mLevelNumber != LastLevel)
            {
                mNextLevelNumber = to_wstring(stoi(mLevelNumber) + 1);
                
            }
            // otherwise the next level is the last level
            else
            {
                mNextLevelNumber = LastLevel;
            }

            mNextLevelFilename = L"levels/level" + mNextLevelNumber + L".xml";
            
        }
    }

    if (mLevelActive)
    {
        // check to see if we need to spawn a new balloon and reset the timer
        double secondsPerBalloon = 1.0 / mBalloonSpawnRate;
        mTimeSinceSpawn = mTimeSinceSpawn + elapsed;
        if ((mTimeSinceSpawn >= secondsPerBalloon) && (mNumBalloonsToSpawn > 0))
        {
            // get the first tile to spawn a balloon on
            CItemVisitorFindRoad visitor(mStartingX, mStartingY);
            Accept(&visitor);
            auto startingRoad = visitor.GetRoad();

            // spawn the balloon
            auto balloon = make_shared<CItemBalloon>(this, mGame);
            mDeferredAdds.push_back(balloon);
            startingRoad->AcceptBalloon(balloon);
            mTimeSinceSpawn = 0.0;

            mNumBalloonsToSpawn--;
        }
    }


    // see if we should call the ghost spawner
    if (mLevelNumber == L"3" && mLevelActive)
    {
        SpawnGhost();
    }

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    // if any item was to be added during the call to item->Update() above,
    // it should now be added into mItems
    for (auto item : mDeferredAdds)
    {
        mItems.push_back(item);
    }
    mDeferredAdds.clear();
 
    // delete (remove) the items if necessary
    for (auto deleteMe : mItemsToDelete)
    {
        auto indexIter = find(mItems.begin(), mItems.end(), deleteMe);
        if (indexIter != mItems.end())
            mItems.erase(indexIter);
    }
}


/** Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CLevel::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}


/**
* Handle a click on the level area when the level is active
* \param x X location clicked on (pixels)
* \param y Y location clicked on (pixels)
*/
void CLevel::OnLButtonDown(int x, int y)
{

    CItemVisitorFindTower towerFinder(x, y);
    Accept(&towerFinder);
    CTowerOwen* tower = towerFinder.GetOwenTower();

    // if we clicked on a Dr. Owen tower, there's stuff we need to do...
    if (tower != nullptr) {
        // clear all of the owens on the grid
        towerFinder.SetRemoveDrOwens(true);
        Accept(&towerFinder);

        // this tower now has Dr. Owen on it
        tower->SetDrOwen(true);
    }
}