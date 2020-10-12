/**
 * \file Game.h
 *
 * \author PaulaRed
 *
 * Main Game class that will be the most important component of Towers 2020
 */

#pragma once
#include <map>
#include <string>
#include <memory>
#include "ImageMap.h"
#include "Item.h"


class CGame
{
public:
    CGame();
    
    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);
    void OnLButtonDown(int x, int y);

private:
    /// Game area in virtual pixels
    const static int Width = 1224;

    /// Game area height in virtual pixels
    const static int Height = 1024;

    /// The game view's scale factor
    float mScale;

    /// The viewing window's offset in the x-direction
    float mXOffset;

    /// the viewing window's offset in the y-direction
    float mYOffset;

    /// map that links image bitmaps to their respective image id
    CImageMap mImageMap;

    /// All of the items to add to our game
    std::vector<std::shared_ptr<CItem> > mItems;
};