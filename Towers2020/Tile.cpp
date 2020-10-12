/**
 * \file Tile.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Tile.h"
#include "Game.h"
#include "ImageMap.h"

using namespace std;

/// grass1 filename
const wstring grassOneImageName = L"images/grass1.png";

/// grass1 id number
const wstring grassOneID = L"i007";

/// grass2 filename
const wstring grassTwoImageName = L"images/grass2.png";

/// grass2 id number
const wstring grassTwoID = L"i008";


/**
* Constructor
* \param game The Game this item is a member of
* \param field The field this item is a member of
* \param imageID The image id for this item
*/
CTile::CTile(CGame* game, CGameField* field, const std::wstring& imageID) 
	: CItem(game, field, imageID)
{

	game->AddImage(grassOneID, grassOneImageName);
	game->AddImage(grassTwoID, grassTwoImageName);
}

