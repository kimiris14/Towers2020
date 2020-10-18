/**
 * \file GamePallette.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "GamePallette.h"
#include <string>

using namespace Gdiplus;
using namespace std;

/**
* Constructor
* \param game The Game this Game Pallette is a member of
*/
CGamePallette::CGamePallette(CGame* game) : mGame(game)
{
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
    Gdiplus::Font font2(&fontFamily, 50);

    //Draw the score in white
    SolidBrush yellow(Color(255, 255, 0));
    wstring scorew = L"Score";
    graphics->DrawString(scorew.c_str(),  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1050, 500),   // Draw to the center of the game palette
        &yellow);    // The brush to draw the text with

    //Draw the score Value in white
    wstring score = to_wstring(mScore);
    graphics->DrawString(score.c_str(),  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font2,      // The font to use
        PointF(1080, 550),   // Draw to the center of the game palette (and under Score)
        &yellow);    // The brush to draw the text with
}
