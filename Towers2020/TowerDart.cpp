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

/// dart balloon filename
const wstring dartImageName = L"images/tower8.png";

/// dart id number
///const int tower8 = ; //not yet assigned


/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CTowerDart::CTowerDart(CLevel* level, int imageID)
	: CTower(level, imageID)
{

}

/**
* Draw the item from the corner
* \param game A pointer to the game object that holds graphics information
* \param graphics The graphics context to draw on
*/
void CTowerDart::Draw(CGame* game, Gdiplus::Graphics* graphics)
{
}

/**
* Set item location
* \param x X location
* \param y Y location
*/
void CTowerDart::SetLocation(double x, double y)
{
}