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

    // if the tower was dropped outside of the grid, return false
    if ((gridX < 0) || (gridX > (GetLevel()->GetWidth() -  1)) ||
        (gridY < 0) || (gridY > (GetLevel()->GetHeight() - 1)))
        return false;

    // find the tile on this grid.



    if (x < 0)
    {
        x = ((x + spacing / 2) / spacing) * spacing - spacing;
    }
    else
    {
        x = ((x + spacing / 2) / spacing) * spacing;
    }

    if (y < 0)
    {
        y = ((y + spacing / 2) / spacing) * spacing - spacing;
    }
    else
    {
        y = ((y + spacing / 2) / spacing) * spacing;
    }

}

