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
const wstring roadEWImageName = L"images/roadEW.png";

/// roadEW id number
const int roadEWID = 1;

/// roadNS filename
const wstring roadNSImageName = L"images/roadNS.png";

/// roadNS id number
const int roadNSID = 2;

/// roadSE filename
const wstring roadSEImageName = L"images/roadSE.png";

/// roadSE id number
const int roadSEID = 3;

/// roadSW filename
const wstring roadSWImageName = L"images/roadSW.png";

/// roadSW id number
const int roadSWID = 4;

/// roadNE filename
const wstring roadNEImageName = L"images/roadNE.png";

/// roadNE id number
const int roadNEID = 5;

/// roadNW filename
const wstring roadNWImageName = L"images/roadNW.png";

/// roadNW id number
const int roadNWID = 6;


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemTileRoad::CItemTileRoad(CLevel* level, CGame* game, int imageID)
    : CItemTile(level, game, imageID)

{
    game->AddImage(roadEWID, roadEWImageName);
    game->AddImage(roadNSID, roadNSImageName);
    game->AddImage(roadSEID, roadSEImageName);
    game->AddImage(roadSWID, roadSWImageName);
    game->AddImage(roadNEID, roadNEImageName);
    game->AddImage(roadNWID, roadNWImageName);
}



