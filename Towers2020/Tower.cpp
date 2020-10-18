/**
 * \file Tower.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Tower.h"
#include "Level.h"
#include "ItemVisitorFindTile.h"


 /**
 * Since this class inherits from CTile, the drawing does not draw from the center like
 * a regular CItem. So, this draw function is simply just an upcall to CItem's.
 * \param graphics The graphics context to draw on
 */
void CTower::Draw(Gdiplus::Graphics* graphics)
{
    CItem::Draw(graphics);
}

/**
 *  Force the tower to a regular grid if there is a place for it
 *
 * This version works correctly for negative coordinates.
 *
 * \returns true if the placement was successful, false otherwise. If false, the calling
 * function should remove the tower from the grid.
 */
bool CTower::Place()
{
    int spacing = CItemTile::TileHeight;

    auto x = (int)GetX();
    auto y = (int)GetY();

    int gridX = x / spacing;
    int gridY = y / spacing;

    int levelWidth = GetLevel()->GetWidth();
    int levelHeight = GetLevel()->GetHeight();

    // if the tower was dropped outside of the grid, return false
    if ((gridX < 0) || (gridX > (levelWidth  - 1)) ||
        (gridY < 0) || (gridY > (levelHeight - 1)))
        return false;

    // find the tile on this grid.
    CItemVisitorFindTile visitor(gridX, gridY);
    GetLevel()->Accept(&visitor);
    auto currentTile = visitor.GetTile();

    // if there was no tile found, then this placement is not good
    if (currentTile == nullptr)
        return false;

    // if the tile is already occupied, then this placement is no good
    if (!currentTile->IsOpen())
        return false;


    // if we made it here, that means there's an open tile available for placement
    currentTile->SetOpen(false);  // no longer open

    // place in the middle of the tile
    double newX = double(gridX) * TileHeight + TileHeight / 2;
    double newY = double(gridY) * TileHeight + TileHeight / 2;

    SetLocation(newX, newY);

    return true;

}

