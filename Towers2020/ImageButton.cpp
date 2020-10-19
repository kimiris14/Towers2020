#include "pch.h"
#include "ImageButton.h"
#include "ImageMap.h"
#include "Game.h"
#include <string>

using namespace std;
using namespace Gdiplus;


/**
* Constructor
* \param game The game the buttons are in
* \param imageID The imageID for this button
* \param x The x location for the button
* \param y The y location for the button
*/
CImageButton::CImageButton(CGame* game, int imageID, int x, int y)
    : CItem(nullptr, game, imageID)
{
    SetLocation(x, y);
}
