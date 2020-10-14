/**
 * \file TileRoad.h
 *
 * \author PaulaRed
 *
 * Class for the Tile Road in the game field. 
 */

#pragma once
#include "ItemTile.h"
#include "ItemBalloon.h"

class CTileRoad :
    public CItemTile
{
    CTileRoad(CLevel* level, CGame* game, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CTileRoad() = delete;

    ///  Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    ~CTileRoad() {}

private:

    /// The image of this tile
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;

    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

    /// Road tile pointer to move East/West
    CTileRoad* mRoadEW = nullptr;

    /// Road tile pointer to move North/South
    CTileRoad* mRoadNS = nullptr;

    /// Road tile pointer to move North/East
    CTileRoad* mRoadNE = nullptr;

    /// Road tile pointer to move North/West
    CTileRoad* mRoadNW = nullptr;

    /// Road tile pointer to move South/East
    CTileRoad* mRoadSE = nullptr;

    /// Road tile pointer to move South/West
    CTileRoad* mRoadSW = nullptr;

    ///List of current balloons over this tile
    std::vector<std::shared_ptr<CItemBalloon>> mTileBalloons;
};

