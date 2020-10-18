/**
 * \file ItemVisitorFindRoad.h
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


/** Item visitor to find roads */
class CItemVisitorFindRoad : public CItemVisitor
{
public:

    CItemVisitorFindRoad() = delete;

    /** Constructor
     * \param x The target X value to find
     * \param y The target Y value to find
     */
    CItemVisitorFindRoad(int x, int y) : mTargetX(x), mTargetY(y) {}

    virtual ~CItemVisitorFindRoad() {}


    virtual void VisitRoad(CItemTileRoad* road);


    /** Getter for the road tile that was found (if at all)
    * \returns A pointer to the found tile */
    CItemTileRoad* GetRoad() { return mRoad; }

private:

    /// The target X index we are looking for
    const int mTargetX;

    /// The target Y index we are looking for
    const int mTargetY;

    /// If we find a road tile at the given index, this pointer will update
    /// to point to the road tile that was found
    CItemTileRoad* mRoad = nullptr;

};