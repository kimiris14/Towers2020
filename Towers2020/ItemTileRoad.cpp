/**
 * \file ItemTileRoad.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemTileRoad.h"
#include "ImageMap.h"
#include "ItemTile.h"
#include "Game.h"
#include <algorithm>

using namespace std;

/// roadEW filename
const wstring RoadEWImageName = L"images/roadEW.png";

/// roadEW id number
const int RoadEWID = 1;

/// roadNS filename
const wstring RoadNSImageName = L"images/roadNS.png";

/// roadNS id number
const int RoadNSID = 2;

/// roadSE filename
const wstring RoadSEImageName = L"images/roadSE.png";

/// roadSE id number
const int RoadSEID = 3;

/// roadSW filename
const wstring RoadSWImageName = L"images/roadSW.png";

/// roadSW id number
const int RoadSWID = 4;

/// roadNE filename
const wstring RoadNEImageName = L"images/roadNE.png";

/// roadNE id number
const int RoadNEID = 5;

/// roadNW filename
const wstring RoadNWImageName = L"images/roadNW.png";

/// roadNW id number
const int RoadNWID = 6;


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemTileRoad::CItemTileRoad(CLevel* level, int imageID)
    : CItemTile(level, imageID)

{
    level->AddImage(RoadEWID, RoadEWImageName);
    level->AddImage(RoadNSID, RoadNSImageName);
    level->AddImage(RoadSEID, RoadSEImageName);
    level->AddImage(RoadSWID, RoadSWImageName);
    level->AddImage(RoadNEID, RoadNEImageName);
    level->AddImage(RoadNWID, RoadNWImageName);

    if (imageID == RoadEWID) {
        mRoadType = L"EW";
    }
    else if (imageID == RoadNSID)
    {
        mRoadType = L"NS";
    }
    else if (imageID == RoadSEID)
    {
        mRoadType = L"SE";
    }
    else if (imageID == RoadSWID)
    {
        mRoadType = L"SW";
    }
    else if (imageID == RoadNEID)
    {
        mRoadType = L"NE";
    }
    else if (imageID == RoadNWID)
    {
        mRoadType = L"NW";
    }
}


/// Accepts a new balloon to be held on this road tile
/// \param balloon The balloon object to add
void CItemTileRoad::AcceptBalloon(std::shared_ptr<CItemBalloon> balloon)
{
    mBalloons.push_back(balloon);
}



/**
 * Place the balloon on the North/West tile, where
 * forward motion is assumed to be from a North entrance
 * to a West exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonNW(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + t * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally left
        x = GetX() + (1 - t) * GetWidth();
    }

    balloon->SetLocation(x, y);
}


/**
 * Place the balloon on the South/West tile, where
 * forward motion is assumed to be from a South entrance
 * to a West exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonSW(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically up
        y = GetY() + (1 - t) * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally left
        x = GetX() + (1 - t) * GetWidth();
    }

    balloon->SetLocation(x, y);
}

/**
 * Place the balloon on the East/West tile, where
 * forward motion is assumed to be from an East entrance
 * to a West exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonEW(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

    // This is for the entire path
    // Moving horizontally left
    x = GetX() + (1 - t) * GetWidth();

    balloon->SetLocation(x, y);
}

/**
 * Place the balloon on the North/South tile, where
 * forward motion is assumed to be from a North entrance
 * to a South exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonNS(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

 
    // The balloon only moves in one direction on this tile
    // Moving vertically down
    y = GetY() + t * GetHeight();


    balloon->SetLocation(x, y);
}

/**
 * Place the balloon on the North/East tile, where
 * forward motion is assumed to be from a North entrance
 * to an East exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonNE(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically down
        y = GetY() + t * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally right
        x = GetX() + t * GetWidth();
    }

    balloon->SetLocation(x, y);
}

/**
 * Place the balloon on the South/East tile, where
 * forward motion is assumed to be from a South entrance
 * to an East exit.
 * @param balloon The balloon we are placing.
 */
void CItemTileRoad::PlaceBalloonSE(std::shared_ptr<CItemBalloon> balloon)
{
    // Current t value for this balloon
    auto t = balloon->GetT();

    // Initially set to the center of the file in each dimension
    auto y = GetY() + GetHeight() / 2;
    auto x = GetX() + GetWidth() / 2;

    // if this tile is reversed, invert T so that we move in the opposite direction
    if (IsReversed())
    {
        t = 1 - t;
    }

    if (t < 0.5)
    {
        // First half of path
        // Moving vertically up
        y = GetY() + (1 - t) * GetHeight();
    }
    else
    {
        // Second half of path
        // Moving horizontally right
        x = GetX() + t * GetWidth();
    }

    balloon->SetLocation(x, y);
}




/// This will handle all of the road updates for this road tile.
/// After iterating through all of the balloons on this tile
/// and updating their locations, if one of them has a T-value
/// over 1.0, subtract 1.0 and move to the next tile.
/// \param elapsed The number of seconds elapsed since last draw
void CItemTileRoad::Update(double elapsed) 
{
    vector<shared_ptr<CItemBalloon>> toMove;

    for (auto balloon : mBalloons)
    {
        // we need to move the balloon after updating these balloons
        if (balloon->GetT() >= 1.0)
        {
            balloon->SetT(balloon->GetT() - 1.0);
            toMove.push_back(balloon);
        }
        // update the position of the balloon on this tile
        else
        {
            if (mRoadType == L"EW")
                PlaceBalloonEW(balloon);
            else if (mRoadType == L"NS")
                PlaceBalloonNS(balloon);
            else if (mRoadType == L"NE")
                PlaceBalloonNE(balloon);
            else if (mRoadType == L"NW")
                PlaceBalloonNW(balloon);
            else if (mRoadType == L"SE")
                PlaceBalloonSE(balloon);
            else if (mRoadType == L"SW")
                PlaceBalloonSW(balloon);
        }
    }

    // now we need to deal with the balloons that have moved off the tile
    for (auto balloon : toMove)
    {
        // remove from this balloon from this tile's list
        auto indexIter = find(mBalloons.begin(), mBalloons.end(), balloon);
        if (indexIter != mBalloons.end())
            mBalloons.erase(indexIter);

        if (mNorth != nullptr)
            mNorth->AcceptBalloon(balloon);
        else if (mSouth != nullptr)
            mSouth->AcceptBalloon(balloon);
        else if (mEast != nullptr)
            mEast->AcceptBalloon(balloon);
        else if (mWest != nullptr)
            mWest->AcceptBalloon(balloon);
        else
        {
            // THIS BALLOON HAS ESCAPED!!!!!!!!!!!!!!!!!!
            GetLevel()->EscapedBalloon(balloon);
        }
    }
}








