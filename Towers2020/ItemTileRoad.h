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


    virtual void Update(double elapsed) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRoad(this); }

    /// Set the road type
    /// \param type The type of the road - "NS" "EW" etc...
    void SetType(std::wstring type) { mRoadType = type; }

    /// Set the reverse path boolean
    /// \param reverse The boolean true if the balloon travels in reverse
    void SetReversedDirection(bool reverse) { mRoadDirectionReversed = reverse; }

    /// Get the road type
    /// \returns the type of road "SW" "EW" etc.
    std::wstring GetType() const { return mRoadType; }

    /// Get the road direction
    /// \returns true if the road's direction in reversed
    bool IsReversed() const { return mRoadDirectionReversed; }

    /// Set the next road tile in the north direction
    /// \param next The next road tile to go to
    void SetNextNorth(CItemTileRoad* next) { mNorth = next; }

    /// Set the next road tile in the south direction
    /// \param next The next road tile to go to
    void SetNextSouth(CItemTileRoad* next) { mSouth = next; }

    /// Set the next road tile in the east direction
    /// \param next The next road tile to go to
    void SetNextEast(CItemTileRoad* next) { mEast = next; }

    /// Set the next road tile in the west direction
    /// \param next The next road tile to go to
    void SetNextWest(CItemTileRoad* next) { mWest = next; }


    void AcceptBalloon(std::shared_ptr<CItemBalloon> balloon);

    void PlaceBalloonNW(std::shared_ptr<CItemBalloon> balloon);
    void PlaceBalloonSW(std::shared_ptr<CItemBalloon> balloon);
    void PlaceBalloonEW(std::shared_ptr<CItemBalloon> balloon);
    void PlaceBalloonNS(std::shared_ptr<CItemBalloon> balloon);
    void PlaceBalloonNE(std::shared_ptr<CItemBalloon> balloon);
    void PlaceBalloonSE(std::shared_ptr<CItemBalloon> balloon);


    /// Getter for if the tile is open for tower placement or not
    /// \returns False, since all roads are occupied by default
    virtual bool IsOpen() { return false; }

private:

    /// This stores the type of road tile (ex. "EW" or "NS")
    std::wstring mRoadType = L"";

    /// This boolean is true when a NS road tile actually flows from S to N, or of the like.
    bool mRoadDirectionReversed = false;

    /// Road tile pointer to move north
    CItemTileRoad* mNorth = nullptr;

    /// Road tile pointer to move south
    CItemTileRoad* mSouth = nullptr;

    /// Road tile pointer to move east
    CItemTileRoad* mEast = nullptr;

    /// Road tile pointer to move west
    CItemTileRoad* mWest = nullptr;


    ///List of current balloons over this tile
    std::vector<std::shared_ptr<CItemBalloon>> mBalloons;
};

