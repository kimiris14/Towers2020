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
class CTile :
    public CItem
{
public:

    CTile(CGame* game, CGameField* field, const std::wstring& imageID);

    ///  Default constructor (disabled)
    CTile() = delete;

    ///  Copy constructor (disabled)
    CTile(const CTile&) = delete;

    ~CTile() {}

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    //virtual void Draw(Gdiplus::Graphics* graphics);

private:

};

