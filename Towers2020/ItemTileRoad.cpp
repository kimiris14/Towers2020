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
CItemTileRoad::CItemTileRoad(CLevel* level, CGame* game, int imageID)
    : CItemTile(level, game, imageID)

{
    game->AddImage(RoadEWID, RoadEWImageName);
    game->AddImage(RoadNSID, RoadNSImageName);
    game->AddImage(RoadSEID, RoadSEImageName);
    game->AddImage(RoadSWID, RoadSWImageName);
    game->AddImage(RoadNEID, RoadNEImageName);
    game->AddImage(RoadNWID, RoadNWImageName);

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



