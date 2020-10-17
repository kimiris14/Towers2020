/**
 * \file TowerDart.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "TowerDart.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;




/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CTowerDart::CTowerDart(CLevel* level, CGame* game)
	: CTower(level, game, TowerImageID)
{
	// the image ID is not properly set in the CTower constructor because it is
	// not yet initialized. This fixes that
	SetImageID(TowerImageID);

	level->AddImage(TowerImageID, TowerImageName);
}
