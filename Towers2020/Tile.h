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

    /**
    * Set the image for this item
    * \param imageID The id for the image
    */
    void SetImage(const std::wstring& imageID);

    /**  The X location of the center of the tile
    * \returns X location in pixels */
    int GetX() const { return mXlocation; }

    /**  The Y location of the center of the tile
    * \returns Y location in pixels */
    int GetY() const { return mYlocation; }

    /**  Set the item location
    * \param x X location
    * \param y Y location */
    void SetLocation(int x, int y) { mXlocation = x; mYlocation = y; }

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    //virtual void Draw(Gdiplus::Graphics* graphics);

private:
    /// X location of tile placed
    int mXlocation = 0;
    
    /// Y location of tile placed
    int mYlocation = 0;

    /// The image of this tile
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;

    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

    /// The field that this item is a part of
    CGameField* mField;

    /// The game that this item is a part of
    CGame* mGame;

    /// The image ID for the image that represents this Item
    const std::wstring& mImageID;
 


};

