/**
 * \file GamePallette.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "Game.h"
#include "GamePallette.h"
#include "Item.h"
#include "ImageButton.h"
#include "TowerDart.h"
#include "TowerRing.h"
#include "TowerBomb.h"
#include "GoButton.h"
#include <string>

using namespace Gdiplus;
using namespace std;

/// the x-location of the tower buttons on screen in pixels
const int TowerButtonXLocation = 1124;

/// the y-location of the bomb tower button in pixels
const int BombTowerY = 300;

/// the y-location of the dart tower button in pixels
const int DartTowerY = 200;

/// the y-location of the ring tower button in pixels
const int RingTowerY = 100;

/// they y-location of the go button in pixels
const int GoButtonY = 900;

/**
* Constructor
* \param game The Game this Game Pallette is a member of
*/
CGamePallette::CGamePallette(CGame* game) : mGame(game)
{
    // create the buttons and push them onto the button list
    auto tempDartTower = make_shared<CTowerDart>(nullptr, game);
    int dartImageID = tempDartTower->GetImageID();
    mDartTowerButton = make_shared<CImageButton>(game, dartImageID, TowerButtonXLocation, DartTowerY);

    auto tempRingTower = make_shared<CTowerRing>(nullptr, game);
    int ringImageID = tempRingTower->GetImageID();
    mRingTowerButton = make_shared<CImageButton>(game, ringImageID, TowerButtonXLocation, RingTowerY);

    auto tempBombTower = make_shared<CTowerBomb>(nullptr, game);
    int bombImageID = tempBombTower->GetImageID();
    mBombTowerButton = make_shared<CImageButton>(game, bombImageID, TowerButtonXLocation, BombTowerY);

    // mTowerButtons.push_back(make_shared<CImageButton>(this, 102, 1090, 400));

    // mTowerButtons.push_back(make_shared<CImageButton>(this, 101, 1090, 200));

    mGoButton = make_shared<CGoButton>(game, TowerButtonXLocation, GoButtonY);
}

/**
* Draw the item
* \param graphics The graphics context to draw on
*/
void CGamePallette::Draw(Gdiplus::Graphics* graphics)
{
    //Font 
    FontFamily fontFamily(L"Arial");
    
    //Font size for Score
    Gdiplus::Font font(&fontFamily, 30);

    //Font size for actual score value
    Gdiplus::Font font2(&fontFamily, 40);

    //Draw the score in white
    SolidBrush yellow(Color(255, 255, 0));
    wstring scorew = L"Score";
    graphics->DrawString(scorew.c_str(),  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1050, 400),   // Draw to the center of the game palette
        &yellow);    // The brush to draw the text with

    //Draw the score Value in yellow
    wstring score = to_wstring(mScore);
    graphics->DrawString(score.c_str(),  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font2,      // The font to use
        PointF(1060, 450),   // Draw to the center of the game palette (and under Score)
        &yellow);    // The brush to draw the text with


    // draw the buttons
    if (mDartTowerButton != nullptr)
        mDartTowerButton->Draw(graphics);
    if (mRingTowerButton != nullptr)
        mRingTowerButton->Draw(graphics);
    if (mBombTowerButton != nullptr)
        mBombTowerButton->Draw(graphics);
    if (mGoButton != nullptr && mGame->GetLevel()->IsActive() == false)
        mGoButton->Draw(graphics);
}

/**
* Handle a click on the game area
* \param x X location clicked on
* \param y Y location clicked on
* \returns A new tower object if one of the tower buttons was pressed
*/
std::shared_ptr<CItem> CGamePallette::OnLButtonDown(int x, int y)
{
    // only make towers draggable if 2 seconds have passed
    if (mDartTowerButton != nullptr && mDartTowerButton->HitTest(x, y) && mGame->GetLevel()->IsTitleDisplayed() != true) 
    {
        return make_shared<CTowerDart>(mGame->GetLevel().get(), mGame );
    }

    if (mRingTowerButton != nullptr && mRingTowerButton->HitTest(x, y) && mGame->GetLevel()->IsTitleDisplayed() != true)
    {
        return make_shared<CTowerRing>(mGame->GetLevel().get(), mGame);
    }

    if (mBombTowerButton != nullptr && mBombTowerButton->HitTest(x, y) && mGame->GetLevel()->IsTitleDisplayed() != true)
    {
        return make_shared<CTowerBomb>(mGame->GetLevel().get(), mGame);
    }

    if (mGoButton != nullptr && mGoButton->HitTest(x,y) && mGame->GetLevel()->IsTitleDisplayed() != true)
    {
        mGame->GetLevel()->Start();
    }
    return nullptr;
}
