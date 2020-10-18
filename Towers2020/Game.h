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
#include "GamePallette.h"


/**
 * The overall class that will handle all basic game functionality. This will store
 * levels and handle the overall structure of gameplay
 */
class CGame
{
public:

    CGame();
    
    void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

    bool AddImage(int imageID, std::wstring imageFile);

    std::shared_ptr<Gdiplus::Bitmap> GetImage(int imageID);

    void Update(double elapsed);

    /// Starts the current level
    void StartLevel() { mCurrentLevel->Start(); }

    /// A getter for the game pallette (created in the constructor)
    /// \returns A shared pointer to the game's pallette
    std::shared_ptr<CGamePallette> GetPallette() { return mGamePallette; }

    /// A getter for the game's current level
    /// \returns A shared pointer to the game's current level
    std::shared_ptr<CLevel> GetLevel() { return mCurrentLevel; }

    /// A setter for the game's current level
    /// \param level The new level for the game
    void SetLevel(std::shared_ptr<CLevel> level) { mCurrentLevel = level; }

    void OnLButtonDown(int x, int y);
    void OnMouseMove(int x, int y, UINT nFlags);


private:

    /// This is where an item will be stored if it is grabbed with the mouse
    std::shared_ptr<CItem> mGrabbedTower = nullptr;

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
    std::shared_ptr<CLevel> mCurrentLevel = nullptr;

    /// map that links image bitmaps to their respective image id
    std::map<int, std::shared_ptr<Gdiplus::Bitmap>> mImageMap;

    /// A pointer to the game pallette. The game should "own" the pallette
    std::shared_ptr<CGamePallette> mGamePallette = nullptr;

};