/**
 * \file ItemTile.h
 *
 * \author PaulaRed
 *
 * Base class for any tile in the game
 */

#pragma once
#include <memory>
#include <string>
#include "ImageMap.h"
#include "Item.h"

/**
 * Base class for any tile in the game 
 */
class CItemTile :
    public CItem
{
public:

    CItemTile(CLevel* level, CGame* game, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CItemTile() = delete;

    ///  Copy constructor (disabled)
    CItemTile(const CItemTile&) = delete;

    ~CItemTile() {}

private:

};

