/**
 * \file TileRoad.cpp
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
const wstring roadEWID = L"i001";

/// roadNS filename
const wstring roadNSImageName = L"images/roadNS.png";

/// roadNS id number
const wstring roadNSID = L"i002";

/// roadSE filename
const wstring roadSEImageName = L"images/roadSE.png";

/// roadSE id number
const wstring roadSEID = L"i003";

/// roadSW filename
const wstring roadSWImageName = L"images/roadSW.png";

/// roadSW id number
const wstring roadSWID = L"i004";

/// roadNE filename
const wstring roadNEImageName = L"images/roadNE.png";

/// roadNE id number
const wstring roadNEID = L"i005";

/// roadNW filename
const wstring roadNWImageName = L"images/roadNW.png";

/// roadNW id number
const wstring roadNWID = L"i006";


/**
* Constructor
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemTileRoad::CItemTileRoad(CLevel* level, CGame* game, const std::wstring& imageID)
    : CItemTile(level, game, imageID)

{
    mImageMap.AddImage(roadEWID, roadEWImageName);
    mImageMap.AddImage(roadNSID, roadNSImageName);
    mImageMap.AddImage(roadSEID, roadSEImageName);
    mImageMap.AddImage(roadSWID, roadSWImageName);
    mImageMap.AddImage(roadNEID, roadNEImageName);
    mImageMap.AddImage(roadNWID, roadNWImageName);
}



