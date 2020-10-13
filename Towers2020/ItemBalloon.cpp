/**
 * \file ItemBalloon.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ItemBalloon.h"
#include "ImageMap.h"
#include "Game.h"
#include "GameField.h"

using namespace std;


/// red balloon filename
const wstring redBalloonImageName = L"red-balloon";

/// red balloon id number
const wstring redBalloonID = L"i044"; //assigned

/**
* Constructor
* \param game The Game this item is a member of
* \param field The field this item is a member of
* \param imageID The image id for this item
*/
CItemBalloon::CItemBalloon(CGame* game, CGameField* field, const std::wstring& imageID): CItem(game, field, imageID)
   
{
    mImageMap.AddImage(redBalloonID, redBalloonImageName);
}

//Add Pop declaration here