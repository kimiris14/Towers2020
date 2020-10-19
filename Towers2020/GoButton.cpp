/**
 * \file GoButton.cpp
 *
 * \author PaulaRed
 *
 * Class for the go button
 */

#include "pch.h"
#include "GoButton.h"
#include "Game.h"

using namespace std;

/// go button image name
const wstring goButtonImageName = L"images/button-go.png";

/// go button id number
const int goButtonImageID = 500;

/**
* Constructor
* \param game The game object that this item is a part of
* \param imageID The image ID for this item
* \param x The x location for this item in pixels
* \param y The y location for this item in pixels
*/
CGoButton::CGoButton(CGame* game, int x, int y)
	: CImageButton(game, goButtonImageID, x, y)
{

	game->AddImage(goButtonImageID, goButtonImageName);
}