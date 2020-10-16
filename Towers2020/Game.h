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
#include "Item.h"
#include "Level.h"


/**
 * The overall class that will handle all basic game functionality. This will store
 * levels and handle the overall structure of gameplay
 */
class CGame
{
public:

    CGame();
    
    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    void OnLButtonDown(int x, int y);

    bool AddImage(int imageID, std::wstring imageFile);

    std::shared_ptr<Gdiplus::Bitmap> GetImage(int imageID);

    void Update(double elapsed);

    /// Starts the current level
    void StartLevel() { mCurrentLevel->Start(); }


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

    /// A pointer to the current level (may change later depending on how levels are stored)
    std::unique_ptr<CLevel> mCurrentLevel = nullptr;

    /// map that links image bitmaps to their respective image id
    std::map<int, std::shared_ptr<Gdiplus::Bitmap>> mImageMap;

    /// image list
    std::shared_ptr<Gdiplus::Bitmap> mImageList[100];

};