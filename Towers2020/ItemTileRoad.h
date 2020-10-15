/**
 * \file ItemTileRoad.h
 *
 * \author PaulaRed
 *
 * Class for the Tile Road in the game field. 
 */

#pragma once
#include "ItemTile.h"
#include "ItemBalloon.h"
#include "ItemVisitor.h"



/**
 * This class will handle specific road tile functionality. This includes things like moving 
 * balloons within the actual tile.
 */
class CItemTileRoad :
    public CItemTile
{

public:
    CItemTileRoad(CLevel* level, CGame* game, int imageID);

    ///  Default constructor (disabled)
    CItemTileRoad() = delete;

    ///  Copy constructor (disabled)
    CItemTileRoad(const CItemTileRoad&) = delete;

    /// destructor
    ~CItemTileRoad() {}

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRoad(this); }

private:

    /// Road tile pointer to move East/West
    CItemTileRoad* mRoadEW = nullptr;

    /// Road tile pointer to move North/South
    CItemTileRoad* mRoadNS = nullptr;

    /// Road tile pointer to move North/East
    CItemTileRoad* mRoadNE = nullptr;

    /// Road tile pointer to move North/West
    CItemTileRoad* mRoadNW = nullptr;

    /// Road tile pointer to move South/East
    CItemTileRoad* mRoadSE = nullptr;

    /// Road tile pointer to move South/West
    CItemTileRoad* mRoadSW = nullptr;

    ///List of current balloons over this tile
    std::vector<std::shared_ptr<CItemBalloon>> mTileBalloons;
};

