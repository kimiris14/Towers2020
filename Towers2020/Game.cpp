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
const wstring roadEWImageName = L"images/roadEW.png";

/// roadEW id number
const wstring roadEWID = L"i001";

/// roadNS filename
const wstring roadNSImageName = L"images/roadNS.png";

/// roadNS id number
const wstring roadNSID = L"i002";

/// roadSE filename
const wstring roadSEImageName = L"images/roadSE.png";

/// roadSE id number
const wstring roadSEID = L"i003";

/// roadSW filename
const wstring roadSWImageName = L"images/roadSW.png";

/// roadSW id number
const wstring roadSWID = L"i004";

/// roadNE filename
const wstring roadNEImageName = L"images/roadNE.png";

/// roadNE id number
const wstring roadNEID = L"i005";

/// roadNW filename
const wstring roadNWImageName = L"images/roadNW.png";

/// roadNW id number
const wstring roadNWID = L"i006";

/// house1 filename
const wstring houseOneImageName = L"images/house1.png";

/// house1 id number
const wstring houseOneID = L"i011";

/// house2 filename
const wstring houseTwoImageName = L"images/house2.png";

/// house2 id number
const wstring houseTwoID = L"i012";

/// house3 filename
const wstring houseThreeImageName = L"images/house3.png";

/// house3 id number
const wstring houseThreeID = L"i013";

/// house4a filename
const wstring houseFourAImageName = L"images/house4a.png";

/// house4a id number
const wstring houseFourAID = L"i014";

/// house4b filename
const wstring houseFourBImageName = L"images/house4b.png";

/// house4b id number
const wstring houseFourBID = L"i015";

/// castlea filename
const wstring castleAImageName = L"images/castlea.png";

/// castlea id number
const wstring castleAID = L"i016";

/// castleb filename
const wstring castleBImageName = L"images/castleb.png";

/// castleb id number
const wstring castleBID = L"i017";

/// trees1 filename
const wstring treesOneImageName = L"images/trees1.png";

/// trees1 id number
const wstring treesOneID = L"i018";

/// trees2 filename
const wstring treesTwoImageName = L"images/trees2.png";

/// trees2 id number
const wstring treesTwoID = L"i019";

/// trees3 filename
const wstring treesThreeImageName = L"images/trees3.png";

/// trees3 id number
const wstring treesThreeID = L"i020";

/// trees4 filename
const wstring treesFourImageName = L"images/trees4.png";

/// trees4 id number
const wstring treesFourID = L"i021";

/**
* Game constructor
* Loads the each image necessary for the game once through a map
*/
CGame::CGame()
{
    mImageMap.AddImage(roadEWID,     roadEWImageName);
    mImageMap.AddImage(roadNSID,     roadNSImageName);
    mImageMap.AddImage(roadSEID,     roadSEImageName);
    mImageMap.AddImage(roadSWID,     roadSWImageName);
    mImageMap.AddImage(roadNEID,     roadNEImageName);
    mImageMap.AddImage(roadNWID,     roadNWImageName);
    mImageMap.AddImage(houseOneID,   houseOneImageName);
    mImageMap.AddImage(houseTwoID,   houseTwoImageName);
    mImageMap.AddImage(houseThreeID, houseThreeImageName);
    mImageMap.AddImage(houseFourAID, houseFourAImageName);
    mImageMap.AddImage(houseFourBID, houseFourBImageName);
    mImageMap.AddImage(castleAID,    castleAImageName);
    mImageMap.AddImage(castleBID,    castleBImageName);
    mImageMap.AddImage(treesOneID,   treesOneImageName);
    mImageMap.AddImage(treesTwoID,   treesTwoImageName);
    mImageMap.AddImage(treesThreeID, treesThreeImageName);
    mImageMap.AddImage(treesFourID,  treesFourImageName);
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

/**
 * Load the game level from a .xml XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the aquarium from.
 */
void CGame::Load(const std::wstring& filename)
{
    // I'll fill this once there is a vector of CTiles
}

/**
 * Clear the game data.
 *
 * Deletes all known items in the game.
 */
void CGame::Clear()
{
    // I'll fill this once there is a vector of CTiles
}



