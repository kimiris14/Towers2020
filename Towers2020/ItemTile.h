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
#include "ItemVisitor.h"

/**
 * Base class for any tile in the game 
 */
class CItemTile :
    public CItem
{
public:

    CItemTile(CLevel* level, CGame* game, int imageID);

    ///  Default constructor (disabled)
    CItemTile() = delete;

    ///  Copy constructor (disabled)
    CItemTile(const CItemTile&) = delete;

    /// destructor 
    ~CItemTile() {}

    virtual void SetGridLocation(int x, int y);

    virtual void Draw(Gdiplus::Graphics* graphics) override;

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTile(this); }

    /** Getter for X grid position
     * \returns the X grid index */
    int GetGridX() const { return mGridPositionX; }

    /** Getter for Y grid position
     * \returns the Y grid index */
    int GetGridY() const { return mGridPositionY; }


    /** Getter for standard tile height
     * \returns the height in pixels */
    const int GetHeight() const { return TileHeight; }

    /** Getter for standard tile width
     * \returns the width in pixels */
    const int GetWidth() const { return TileWidth; }


    /// Sets the open boolean for when an item (tower) is placed or removed from the tile.
    /// \param isOpen True if the tile is open for object placement
    virtual void SetOpen(bool isOpen) { mOpen = isOpen; }

    /// Getter for if the tile is open for tower placement or not
    /// \returns True if the tile is open, false if it's occupied.
    virtual bool IsOpen() { return mOpen; }

private:

    /// The X position index when placed on the grid (not pixels!)
    int mGridPositionX = 0;

    /// The Y position index when placed on the grid (not pixels!)
    int mGridPositionY = 0;

    /// the constant height for every tile
    const int TileHeight = 64;

    /// the constant width for every tile
    const int TileWidth = 64;

    /// This boolean represents if this tile is able to have something placed on it, like a tower
    bool mOpen = false;
};

