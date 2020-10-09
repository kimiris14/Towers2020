/**
 * \file Game.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Game.h"
#include <map>
#include <string>

using namespace Gdiplus;
using namespace std;

/// roadEW filename
const wstring roadEWImageName = L"roadEW.png";

/// roadEW id number
const wstring roadEWID = L"i001";

/// roadNS filename
const wstring roadNSImageName = L"roadNS.png";

/// roadNS id number
const wstring roadNSID = L"i002";

/// roadSE filename
const wstring roadSEImageName = L"roadSE.png";

/// roadSE id number
const wstring roadSEID = L"i003";

/// roadSW filename
const wstring roadSWImageName = L"roadSW.png";

/// roadSW id number
const wstring roadSWID = L"i004";

/// roadNE filename
const wstring roadNEImageName = L"roadNE.png";

/// roadNE id number
const wstring roadNEID = L"i005";

/// roadNW filename
const wstring roadNWImageName = L"roadNW.png";

/// roadNW id number
const wstring roadNWID = L"i006";

/// grass1 filename
const wstring grassOneImageName = L"grass1.png";

/// grass1 id number
const wstring grassOneID = L"i007";

/// grass2 filename
const wstring grassTwoImageName = L"grass2.png";

/// grass2 id number
const wstring grassTwoID = L"i008";

/// house1 filename
const wstring houseOneImageName = L"house1.png";

/// house1 id number
const wstring houseOneID = L"i011";

/// house2 filename
const wstring houseTwoImageName = L"house2.png";

/// house2 id number
const wstring houseTwoID = L"i012";

/// house3 filename
const wstring houseThreeImageName = L"house3.png";

/// house3 id number
const wstring houseThreeID = L"i013";

/// house4a filename
const wstring houseFourAImageName = L"house4a.png";

/// house4a id number
const wstring houseFourAID = L"i014";

/// house4b filename
const wstring houseFourBImageName = L"house4b.png";

/// house4b id number
const wstring houseFourBID = L"i015";

/// castlea filename
const wstring castleAImageName = L"castlea.png";

/// castlea id number
const wstring castleAID = L"i016";

/// castleb filename
const wstring castleBImageName = L"castleb.png";

/// castleb id number
const wstring castleBID = L"i017";

/// trees1 filename
const wstring treesOneImageName = L"trees1.png";

/// trees1 id number
const wstring treesOneID = L"i018";

/// trees2 filename
const wstring treesTwoImageName = L"trees2.png";

/// trees2 id number
const wstring treesTwoID = L"i019";

/// trees3 filename
const wstring treesThreeImageName = L"trees3.png";

/// trees3 id number
const wstring treesThreeID = L"i020";

/// trees4 filename
const wstring treesFourImageName = L"trees4.png";

/// trees4 id number
const wstring treesFourID = L"i021";

/**
* Game constructor
* Loads the each image necessary for the game once through a map
*/
CGame::CGame()
{
    mImageMap.insert({ roadEWID, roadEWImageName });
    mImageMap.insert({ roadNSID, roadNSImageName });
    mImageMap.insert({ roadSEID, roadSEImageName });
    mImageMap.insert({ roadSWID, roadSWImageName });
    mImageMap.insert({ roadNEID, roadNEImageName });
    mImageMap.insert({ roadNWID, roadNWImageName });
    mImageMap.insert({ grassOneID, grassOneImageName });
    mImageMap.insert({ grassTwoID, grassTwoImageName });
    mImageMap.insert({ houseOneID, houseOneImageName });
    mImageMap.insert({ houseTwoID, houseTwoImageName });
    mImageMap.insert({ houseThreeID, houseThreeImageName });
    mImageMap.insert({ houseFourAID, houseFourAImageName });
    mImageMap.insert({ houseFourBID, houseFourBImageName });
    mImageMap.insert({ castleAID, castleAImageName });
    mImageMap.insert({ castleBID, castleBImageName });
    mImageMap.insert({ treesOneID, treesOneImageName });
    mImageMap.insert({ treesTwoID, treesTwoImageName });
    mImageMap.insert({ treesThreeID, treesThreeImageName });
    mImageMap.insert({ treesFourID, treesFourImageName });
}

/**
  * Draw the game area
  * \param graphics The GDI+ graphics context to draw on
  * \param width Width of the client window
  * \param height Height of the client window
  */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
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

