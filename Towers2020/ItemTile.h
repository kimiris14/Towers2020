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

    virtual void SetGridLocation(double x, double y);

    virtual void Draw(CGame* game, Gdiplus::Graphics* graphics) override;

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTile(this); }

private:

    /// The X position index when placed on the grid (not pixels!)
    double mGridPositionX;

    /// The Y position index when placed on the grid (not pixels!)
    double mGridPositionY;

};

