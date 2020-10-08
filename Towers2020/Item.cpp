/**
 * \file Item.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Item.h"
#include "GameField.h"


using namespace std;
using namespace Gdiplus;


/**
* Draw the item
* \param graphics The graphics context to draw on
*/
void CItem::Draw(Gdiplus::Graphics* graphics)
{

    // Commented out until CGame support is added for image mapping.

    /*
    unique_ptr<Bitmap> itemBitmap = mGame.GetImage(mImageID);

    double wid = itemBitmap->GetWidth();
    double hit = itemBitmap->GetHeight();

    graphics->DrawImage(itemBitmap.get(),
        float(GetX() - wid / 2), float(GetY() - hit / 2),
        (float)mItemBitmap->GetWidth(), (float)mItemBitmap->GetHeight());
    */
}