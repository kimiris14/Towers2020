/**
 * \file ItemTile.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemTile.h"
#include "Game.h"
#include "ImageMap.h"

using namespace std;

/// grass1 filename
const wstring grassOneImageName = L"images/grass1.png";

/// grass1 id number
const int grassOneID = 7;

/// grass2 filename
const wstring grassTwoImageName = L"images/grass2.png";

/// grass2 id number
const int grassTwoID = 8;


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemTile::CItemTile(CLevel *level, CGame* game, int imageID) 
	: CItem(level, game, imageID)
{

	game->AddImage(grassOneID, grassOneImageName);
	game->AddImage(grassTwoID, grassTwoImageName);
}

