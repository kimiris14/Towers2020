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
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include "ItemVisitor.h"
#include "ItemVisitorFindRoad.h"
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;
using namespace xmlnode;

/**
* Constructor
* \param game The game object that this level belongs to
* \param filename The filename of the XML level definition file for this level
*/
CLevel::CLevel(CGame* game, std::shared_ptr<CGamePallette> pallette, std::wstring filename) :
    mGame(game), mPallette(pallette) {
    Load(filename);
}


/// Gets the image object from the game
/// \param id The item's ID
/// \returns The gdiplus bitmap
std::shared_ptr<Gdiplus::Bitmap> CLevel::GetImage(int id) {
    return mGame->GetImage(id);
}

/**
 * Adds a bitmap to the mImageMap and shows an error message box if appropriate
 * \param imageID The ID to associate with this image
 * \param imageFileName The file for the image to load
 * \returns true if successful, false if failure
 */
bool CLevel::AddImage(int imageID, std::wstring imageFileName) {
    return mGame->AddImage(imageID, imageFileName);
}


/// This function is called by a road tile when a baloon has exited the game.
/// This means that points are lost.
/// \param balloon The shared pointer to the escaped balloon
void CLevel::EscapedBalloon(std::shared_ptr<CItemBalloon> balloon)
{
    mItemsToDelete.push_back(balloon);
    mGame->GetPallette()->DecrementScore(mPointsPerEscape);
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
        bool newEast  = false;
        bool newSouth = false;
        bool newWest  = false;

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
                 ((prevType == L"SE") && ( prevRoad->IsReversed())) ||
                 ((prevType == L"SW") && ( prevRoad->IsReversed())))
        {
            currentY++;  // remember that in computer-land, pixels are from the top left, down
            newSouth = true;
        }

        // the next tile should be to the east (right one index)
        else if (((prevType == L"EW") && ( prevRoad->IsReversed())) ||
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
    for (auto item : mItems) {
        item->Draw(graphics);
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
        item = make_shared<CItemTile>(this, mGame, imageID);
    }

    if (type == L"road")
    {
        item = make_shared<CItemTileRoad>(this, mGame, imageID);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);

        Add(item);
    }

}

/**
* Add an item to the level
* \param item The item we are adding
*/
void CLevel::Add(shared_ptr<CItem> item)
{
    mItems.push_back(item);
}


/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CLevel::Update(double elapsed)
{

    if (mLevelActive)
    {
        mTotalElapsedTime = mTotalElapsedTime + elapsed;

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
            auto balloon = make_shared<CItemBalloon>(this, mGame, mDefaultBalloonID);
            mItems.push_back(balloon);
            startingRoad->AcceptBalloon(balloon);
            mTimeSinceSpawn = 0.0;

            mNumBalloonsToSpawn--;
        }
    }

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

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