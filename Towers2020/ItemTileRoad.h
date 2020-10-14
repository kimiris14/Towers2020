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

class CItemTileRoad :
    public CItemTile
{
    CItemTileRoad(CLevel* level, CGame* game, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CItemTileRoad() = delete;

    ///  Copy constructor (disabled)
    CItemTileRoad(const CItemTileRoad&) = delete;

    ~CItemTileRoad() {}

private:

    /// The image of this tile
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;

    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

    /// Road tile pointer to move East/West
    CItemTileRoad* mRoadEW = nullptr;

    /// Road tile pointer to move North/South
    CItemTileRoad* mRoadNS = nullptr;

    /// Road tile pointer to move North/East
    CItemTileRoad* mRoadNE = nullptr;

    /// Road tile pointer to move North/West
    CItemTileRoad* mRoadNW = nullptr;

    /// Road tile pointer to move South/East
    CItemTileRoad* mRoadSE = nullptr;

    /// Road tile pointer to move South/West
    CItemTileRoad* mRoadSW = nullptr;

    ///List of current balloons over this tile
    std::vector<std::shared_ptr<CItemBalloon>> mTileBalloons;
};

