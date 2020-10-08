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
#include "Item.h"

/**
 * Base class for any tile in the game field
 */
class CTile :
    public CItem
{
public:
    ///  Default constructor (disabled)
    CTile() = delete;

    ///  Copy constructor (disabled)
    CTile(const CTile&) = delete;

    //virtual ~CTile();

    //void SetImage(const std::wstring& file);

    /**  Get the file name for this tile image
     * \returns Filename or blank if none */
    //std::wstring GetFile() { return mFile; }

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
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

    /// The file for this item
    std::wstring mFile;

};

