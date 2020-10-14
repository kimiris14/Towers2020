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

    void AddImage(const std::wstring& imageID, const std::wstring& imageFile);



    /**
    * gets a shared pointer to the game's image map
    * returns A shared pointer to the game's image map
    */
    std::shared_ptr<CImageMap> GetImageMap() const { return mImageMap; }

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
    std::shared_ptr<CImageMap> mImageMap;

};