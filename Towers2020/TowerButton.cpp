#include "pch.h"
#include "TowerButton.h"
#include "ImageMap.h"
#include "Game.h"
#include <string>

using namespace std;
using namespace Gdiplus;


/// dart tower filename
const wstring dartTowerImage = L"images/tower8.png";

/// dart tower id number
const int dartTowerID = 100;

/// ring tower filename
const wstring ringTowerImage = L"images/tower-rings.png";

/// ring tower id number
const int ringTowerID = 101;

/// bomb tower filename
const wstring bombTowerImage = L"images/tower-bomb.png";

/// bomb tower id number
const int bombTowerID = 102;

/**
* Constructor
* \param game The game the buttons are in
* \param level The level set to nullptr
* \param imageID The imageID for this button
* \param x The x location for the button
* \param y The y location for the button
*/
CTowerButton::CTowerButton(CLevel* level, CGame* game, int imageID, int x, int y) 
    : mGame(game)
    ,mImageID(imageID)
    ,mButtonX(x)
    ,mButtonY(y)
{
    mGame->AddImage(dartTowerID, dartTowerImage);
    mGame->AddImage(ringTowerID, ringTowerImage);
    mGame->AddImage(bombTowerID, bombTowerImage);
}


/**
* Draw the tower buttons in the game palette
* \param graphics The graphics context to draw on
*/
void CTowerButton::Draw(Gdiplus::Graphics* graphics)
{
    // grab the images
    shared_ptr<Bitmap> itemBitmap = mGame->GetImage(mImageID);

    // draw them
    graphics->DrawImage(itemBitmap.get(),
        float(mButtonX), float(mButtonY),
        (float)itemBitmap->GetWidth(), (float)itemBitmap->GetHeight());
}


/**
* Test this item to see if it has been clicked on
* \param x X location on the game to test
* \param y Y location on the game to test
* \return true if clicked on */
bool CTowerButton::HitTest(int x, int y)
{
    auto itemImage = mLevel->GetImage(mImageID);

    double wid = itemImage->GetWidth();
    double hit = itemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - mButtonX + wid / 2;
    double testY = y - mButtonY + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = itemImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        itemImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}
