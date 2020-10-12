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
    public CTile
{
    CTileRoad(CGame* game, CGameField* field, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CTileRoad() = delete;

    ///  Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    ~CTileRoad() {}

private:
    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

};

