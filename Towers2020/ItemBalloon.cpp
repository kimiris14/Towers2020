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
const wstring RedBalloonImageName = L"images/red-balloon.png";

/// red balloon id number
const int RedBalloonID = 44; //assigned

/**
* Constructor
* \param level The Level this item is a member of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemBalloon::CItemBalloon(CLevel *level, int imageID) : CItem(level,imageID)
   
{
    level->AddImage(imageID, RedBalloonImageName);
}

//Add Pop declaration here