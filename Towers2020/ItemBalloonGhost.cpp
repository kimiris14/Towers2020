/**
 * \file ItemBalloonGhost.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemBalloonGhost.h"
#include "ItemBalloon.h"
#include "Item.h"
#include "Game.h"


 /**
  * Constructor
  * \param level The level that this balloon belongs to
  * \param game The game that this balloon belongs to
  */
CItemBalloonGhost::CItemBalloonGhost(CLevel* level, CGame* game) : CItemBalloon(level, game)
{
	SetImageID(GhostImageID);
	GetGame()->AddImage(GhostImageID, GhostImage);
}