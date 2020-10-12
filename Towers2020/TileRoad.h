/**
 * \file TileRoad.h
 *
 * \author PaulaRed
 *
 * Class for the Tile Road in the game field. 
 */

#pragma once
#include "Tile.h"


class CTileRoad :
    public CItemTile
{
    CTileRoad(CGame* game, CGameField* field, const std::wstring& imageID);

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

};

