/**
 * \file Game.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "Game.h"
#include "Level.h"
#include "XmlNode.h"
#include "ImageMap.h"
#include "Tower.h"
#include "TowerDart.h"
#include "ItemVisitorFindTile.h"
#include "ImageButton.h"
#include "Item.h"
#include <memory>
#include <map>
#include <string>
#include <Windows.h>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

/// The Default level to load when the game is created
const wstring DefaultLevel = L"levels/level1.xml";


/**
* Game constructor
* Loads the each image necessary for the game once through a map
*/
CGame::CGame()
{

    // create the game pallette
    mGamePallette = make_shared<CGamePallette>(this);

    // load the default level
    mCurrentLevel = make_shared<CLevel>(this, DefaultLevel);

}

/**
  * Draw the game area
  * \param graphics The GDI+ graphics context to draw on
  * \param width Width of the client window
  * \param height Height of the client window
  */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with blackGa
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(Width);
    float scaleY = float(height) / float(Height);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - Width * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - Height * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // from here on you are drawing virtual pixels

    if (mGamePallette != nullptr) {
        mGamePallette->Draw(graphics);
    }

    // draw the level with this graphics context
    if (mCurrentLevel != nullptr) {
        mCurrentLevel->Draw(graphics);
    }

    if (mLevelNumber == 3)
    {
        FontFamily fontFamily(L"Chiller");
        Gdiplus::Font font(&fontFamily, 50, FontStyleBold, UnitPixel);
        // Lettering color
        SolidBrush grey(Color(90, 90, 90));
        graphics->DrawString(L"CSE 335 Graveyard", -1, &font, PointF(400, 10), &grey);
    }
}


/**
* Handle a click on the game area
* \param x X location clicked on (pixels)
* \param y Y location clicked on (pixels)
*/
void CGame::OnLButtonDown(int x, int y)
{

    // convert the x and y clicked pixel coordinates into virtual pixel coordinates
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    // if the current level is active, then the level will handle the click
    if (mCurrentLevel->IsActive())
    {
        mCurrentLevel->OnLButtonDown((int)oX, (int)oY);
    }
    // otherwise, we have to figure out exactly where we clicked
    else
    {

        // did we click an item in the level?
        auto clickedItem = mCurrentLevel->PickUpTower((int)oX, (int)oY);
        if (clickedItem != nullptr)
        {

            // we grabbed an item. Set the pointer in Game
            mGrabbedTower = clickedItem;

        }

        // did we click an item in the game pallette?
        auto newItem = mGamePallette->OnLButtonDown((int)oX, (int)oY);
        if (newItem != nullptr)
        {
            newItem->SetLocation(oX, oY);
            mGrabbedTower = newItem.get();
            mCurrentLevel->AddDeferred(newItem);
        }
    }

}

/**
* Handle a mouse movement on the game area
* \param nFlags Flags associated with the mouse button press
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnMouseMove(int x, int y, UINT nFlags)
{
    // convert the x and y clicked pixel coordinates into virtual pixel coordinates
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;


    // See if an item is currently being moved by the mouse
    if (mGrabbedTower != nullptr)
    {
        // If an item is being moved, we only continue to 
        // move it while the left button is down.
        if (nFlags & MK_LBUTTON)
        {
            mGrabbedTower->SetLocation(oX, oY);
        }
        else
        {

            // attempt to place the tower, then release it
            bool placeSuccessful = mGrabbedTower->Place();

            // remove the tower from the level if the place was not good
            if (!placeSuccessful)
                mGrabbedTower->SetActive(false);

            mGrabbedTower = nullptr;

        }

        // Force the screen to redraw
        // Invalidate();
    }
}



/**
 * Adds a bitmap to the mImageMap and shows an error message box if appropriate
 * \param imageID The ID to associate with this image
 * \param imageFileName The file for the image to load
 * \returns true if successful, false if failure
 */
bool CGame::AddImage(int imageID, std::wstring imageFileName)
{

    auto temp = mImageMap.find(imageID);
    auto temp2 = mImageMap.end();

    // if the image ID is already in the map, do not load it again
    if (mImageMap.find(imageID) != mImageMap.end())
        return true;

    bool success = true;

    // load the image into a bitmap
    shared_ptr<Bitmap> bitmap = shared_ptr<Bitmap>(Bitmap::FromFile(imageFileName.c_str()));
    if (bitmap->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += imageFileName;
        AfxMessageBox(msg.c_str());
        success = false;
    }
    mImageMap[imageID] = bitmap;

    return success;
}


/**
 * Gets one of the game's images from the image map
 * \param imageID The ID for this image
 * \returns The corresponding bitmap object
 */
std::shared_ptr<Gdiplus::Bitmap> CGame::GetImage(int imageID)
{
    // if the image ID is in the map, return the bitmap pointer, otherwise
    // return a nullptr.

    if (mImageMap.find(imageID) != mImageMap.end())
    {
        return mImageMap[imageID];
    }
    else
    {
        return nullptr;
    }
}



/** Handle updates for animation
* \param elapsed The time since the last update in seconds
*/
void CGame::Update(double elapsed)
{
    // load the next level if the current level is complete
    if (mCurrentLevel->IsCompleted() && mCurrentLevel->GetNextLevel() != L"")
    {
        mCurrentLevel = make_shared<CLevel>(this, mCurrentLevel->GetNextLevel());
    }
    mCurrentLevel->Update(elapsed);
}
