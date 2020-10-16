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
CGamePallette::CGamePallette(CGame* game)
{
    mGame = game;
}

/**
* Draw the item
* \param graphics The graphics context to draw on
*/
void CGamePallette::Draw(Gdiplus::Graphics* graphics)
{
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 24);

    //Draw the score in white
    SolidBrush white(Color (255, 255, 255));     
    wstring score = L"Score: " + to_wstring(mScore);
    graphics->DrawString(score.c_str(),  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1050, 500),   // Where to draw (middle right of the screen)
        &white);    // The brush to draw the text with

}
