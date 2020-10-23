/**
 * \file ItemVisitorFindTile.h
 *
 * \author PaulaRed
 *
 * Item visitor to find a road tile at a given index
 */


#pragma once

#include "ItemVisitor.h"

 // Forward references to all item types
class CItemBalloon;
class CItemTile;
class CItemTileRoad;


/** Tile visitor class to find a any given tile */
class CItemVisitorFindTile : public CItemVisitor
{
public:

    CItemVisitorFindTile() = delete;

    /** Constructor
     * \param x The target X value to find (in grid indecies)
     * \param y The target Y value to find (in grid indecies)
     */
    CItemVisitorFindTile(int x, int y) : mTargetX(x), mTargetY(y) {}

    virtual ~CItemVisitorFindTile() {}


    virtual void VisitRoad(CItemTileRoad* road);
    virtual void VisitTile(CItemTile* tile);


    /** Getter for the  tile that was found (if at all)
    * \returns A pointer to the found tile */
    CItemTile* GetTile() { return mTile; }

private:

    /// The target X index we are looking for
    const int mTargetX;

    /// The target Y index we are looking for
    const int mTargetY;

    /// If we find a tile at the given index, this pointer will update
    /// to point to the road tile that was found
    CItemTile* mTile = nullptr;

};