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
#include <memory>
#include <map>
#include <string>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/// house1 filename
const wstring houseOneImageName = L"images/house1.png";

/// house1 id number
const int houseOneID = 11;

/// house2 filename
const wstring houseTwoImageName = L"images/house2.png";

/// house2 id number
const int houseTwoID = 12;

/// house3 filename
const wstring houseThreeImageName = L"images/house3.png";

/// house3 id number
const int houseThreeID = 13;

/// house4a filename
const wstring houseFourAImageName = L"images/house4a.png";

/// house4a id number
const int houseFourAID = 14;

/// house4b filename
const wstring houseFourBImageName = L"images/house4b.png";

/// house4b id number
const int houseFourBID = 15;

/// castlea filename
const wstring castleAImageName = L"images/castlea.png";

/// castlea id number
const int castleAID = 16;

/// castleb filename
const wstring castleBImageName = L"images/castleb.png";

/// castleb id number
const int castleBID = 17;

/// trees1 filename
const wstring treesOneImageName = L"images/trees1.png";

/// trees1 id number
const int treesOneID = 18;

/// trees2 filename
const wstring treesTwoImageName = L"images/trees2.png";

/// trees2 id number
const int treesTwoID = 19;

/// trees3 filename
const wstring treesThreeImageName = L"images/trees3.png";

/// trees3 id number
const int treesThreeID = 20;

/// trees4 filename
const wstring treesFourImageName = L"images/trees4.png";

/// trees4 id number
const int treesFourID = 21;

/**
* Game constructor
* Loads the each image necessary for the game once through a map
*/
CGame::CGame()
{

    // THIS IS JUST HERE FOR TESTING!!!
    mCurrentLevel = make_shared<CLevel>(this, L"levels/level0.xml");
    
    AddImage(houseOneID,   houseOneImageName);
    AddImage(houseTwoID,   houseTwoImageName);
    AddImage(houseThreeID, houseThreeImageName);
    AddImage(houseFourAID, houseFourAImageName);
    AddImage(houseFourBID, houseFourBImageName);
    AddImage(castleAID,    castleAImageName);
    AddImage(castleBID,    castleBImageName);
    AddImage(treesOneID,   treesOneImageName);
    AddImage(treesTwoID,   treesTwoImageName);
    AddImage(treesThreeID, treesThreeImageName);
    AddImage(treesFourID,  treesFourImageName);
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
 


    // draw the level with this graphics context
    if (mCurrentLevel != nullptr) {
        mCurrentLevel->Draw(this, graphics);
    }
    
}


/**
* Handle a click on the game area
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonDown(int x, int y)
{
    // convert the x and y clicked pixel coordinates into virtual pixel coordinates
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

}



/**
 * Adds a bitmap to the mImageMap and shows an error message box if appropriate
 * \param imageID The ID to associate with this image
 * \param imageFileName The file for the image to load
 * \returns true if successful, false if failure
 */
bool CGame::AddImage(int imageID, std::wstring imageFileName)
{

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

