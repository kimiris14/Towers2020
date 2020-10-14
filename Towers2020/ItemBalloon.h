/**
 * \file ItemBalloon.h
 *
 * \author PaulaRed
 *
 * Class for a balloon that enters the game field
 */

#pragma once
#include "Item.h"
#include "ImageMap.h"

class CItemBalloon :
    public CItem
{
public:
    CItemBalloon(CLevel *level, CGame* game, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CItemBalloon() = delete;

    ///  Copy constructor (disabled)
    CItemBalloon(const CItemBalloon&) = delete;

    ~CItemBalloon() {}

    /// Function to get the balloon's t value
    /// <returns> mTvalue The balloon's t value </returns>
    int CItemBalloon::GetTValue() { return mTValue; }

    //Add Pop definition here


private:
    /// The image of this balloon
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;

    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

    /// The balloon's t value
   float mTValue = 0;
};

