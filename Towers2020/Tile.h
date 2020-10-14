/**
 * \file Tile.h
 *
 * \author PaulaRed
 *
 * Base class for any tile in the game field
 */

#pragma once
#include <memory>
#include <string>
#include "GameField.h"
#include "ImageMap.h"
#include "Item.h"

/**
 * Base class for any tile in the game field
 */
class CItemTile :
    public CItem
{
public:

    CItemTile(CGame* game, CGameField* field, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CItemTile() = delete;

    ///  Copy constructor (disabled)
    CItemTile(const CItemTile&) = delete;

    ~CItemTile() {}

private:

};

