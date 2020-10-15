/**
 * \file ItemBalloon.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ItemBalloon.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;


/// red balloon filename
const wstring redBalloonImageName = L"images/red-balloon";

/// red balloon id number
const int redBalloonID = 44; //assigned

/**
* Constructor
* \param level The Level this item is a member of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemBalloon::CItemBalloon(CLevel *level, CGame* game, int imageID) : CItem(level,game,imageID)
   
{
    game->AddImage(redBalloonID, redBalloonImageName);
}

//Add Pop declaration here