/**
 * \file ProjectileDart.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ProjectileDart.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;

/// dart balloon filename
const wstring dartImageName = L"images/dart.png";

/// dart id number
const int dartID = 51; //assigned

 /**
 * Constructor
 * \param level The Level this item is a member of
 * \param game The Game this item is a member of
 * \param imageID The image id for this item
 */
CProjectileDart::CProjectileDart(CLevel* level, CGame* game, int imageID) : CProjectile(level, game, imageID)
{
	level->AddImage(dartID, dartImageName);
}

/**
* Draw the item from the corner
* \param game A pointer to the game object that holds graphics information
* \param graphics The graphics context to draw on
*/
void CProjectileDart::Draw(Gdiplus::Graphics* graphics)
{
}

/**
* Set item location
* \param x X location
* \param y Y location
*/
void CProjectileDart::SetLocation(double x, double y)
{
}
