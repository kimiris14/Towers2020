/**
 * \file Game.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;



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
* Load images once by mapping all images to their respective IDs
*/
void CGame::ImageMap() 
{
    mImageMap.insert({"i001", "roadEW.png"});
    mImageMap.insert({"i002", "roadNS.png"});
    mImageMap.insert({"i003", "roadSE.png"});
    mImageMap.insert({"i004", "roadSW.png"});
    mImageMap.insert({"i005", "roadNE.png"});
    mImageMap.insert({"i006", "roadNW.png"});
    mImageMap.insert({"i007", "grass1.png"});
    mImageMap.insert({"i008", "grass2.png"});
    mImageMap.insert({"i011", "house1.png"});
    mImageMap.insert({"i012", "house2.png"});
    mImageMap.insert({"i013", "house3.png"});
    mImageMap.insert({"i014", "house4a.png"});
    mImageMap.insert({"i015", "house4b.png"});
    mImageMap.insert({"i016", "castlea.png"});
    mImageMap.insert({"i017", "castleb.png"});
    mImageMap.insert({"i018", "trees1.png"});
    mImageMap.insert({"i019", "trees2.png"});
    mImageMap.insert({"i020", "trees3.png"});
    mImageMap.insert({"i021", "trees4.png"});
}

