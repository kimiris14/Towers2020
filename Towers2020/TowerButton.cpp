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
*/
CTowerButton::CTowerButton(CGame* game) : mGame(game)
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
    shared_ptr<Bitmap> dartTowerBitmap = mGame->GetImage(dartTowerID);
    shared_ptr<Bitmap> ringTowerBitmap = mGame->GetImage(ringTowerID);
    shared_ptr<Bitmap> bombTowerBitmap = mGame->GetImage(bombTowerID);

    // draw them
    graphics->DrawImage(dartTowerBitmap.get(),
        float(1090), float(300),
        (float)dartTowerBitmap->GetWidth(), (float)dartTowerBitmap->GetHeight());

    graphics->DrawImage(ringTowerBitmap.get(),
        float(1090), float(200),
        (float)ringTowerBitmap->GetWidth(), (float)ringTowerBitmap->GetHeight());

    graphics->DrawImage(bombTowerBitmap.get(),
        float(1090), float(400),
        (float)bombTowerBitmap->GetWidth(), (float)bombTowerBitmap->GetHeight());
}


/**
* Test this item to see if it has been clicked on
* \param x X location on the game to test
* \param y Y location on the game to test
* \return true if clicked on */
bool CTowerButton::HitTest(int x, int y)
{
    return true;
}