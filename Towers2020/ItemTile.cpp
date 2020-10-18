/**
 * \file ItemTile.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemTile.h"
#include "Game.h"
//#include "ImageMap.h"

using namespace Gdiplus;
using namespace std;



/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
* \param imageID The image id for this item
*/
CItemTile::CItemTile(CLevel *level, CGame* game, int imageID)
	: CItem(level, game, imageID)
{

}


/// Set the item location on the grid
/// \param x X grid location index
/// \param y Y grid location index
void CItemTile::SetGridLocation(int x, int y)
{
	mGridPositionX = x;
	mGridPositionY = y;

	double xPixelLocation = x * TileWidth;
	double yPixelLocation = y * TileHeight;

	SetLocation(xPixelLocation, yPixelLocation);
}



/**
* Draw the item from the corner
* \param graphics The graphics context to draw on
*/
void CItemTile::Draw(Gdiplus::Graphics* graphics)
{

	shared_ptr<Bitmap> itemBitmap = GetGame()->GetImage(GetImageID());

	float wid = static_cast<float>(itemBitmap->GetWidth());
	float hit = static_cast<float>(itemBitmap->GetHeight());

	float xPos = static_cast<float>(GetX()) - 1;
	float yPos = static_cast<float>(GetY()) - 1;

	graphics->DrawImage(itemBitmap.get(), xPos, yPos, wid + 1, hit + 1);
}


/**
 * Load the attributes for an item tile node.
 *
 * Overridden from base class to account for tile grid placemebt
 *
 * \param node The Xml node we are loading the item from
 */
void CItemTile::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	int xGrid = node->GetAttributeIntValue(L"x", 0);
	int yGrid = node->GetAttributeIntValue(L"y", 0);

	SetGridLocation(xGrid, yGrid);
}


