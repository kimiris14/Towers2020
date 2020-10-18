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


/**
* Constructor
* \param level The Level this item is a member of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemBalloon::CItemBalloon(CLevel *level, CGame *game) : CItem(level,game,RedBalloonID)
{
    SetImageID(RedBalloonID);  // base it is uninitialized during the call to CItem constructor
    game->AddImage(RedBalloonID, RedBalloonImageName);
}
