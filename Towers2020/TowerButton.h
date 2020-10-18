/**
 * \file TowerButton.h
 *
 * \author PaulaRed
 *
 * Class for the button images in the game pallette
 */
#pragma once
#include "Item.h"

class CGame;

/**
* Class that places images of the tower buttons in the game palette
*/
class CTowerButton 
{
public:

    CTowerButton(CLevel* level, CGame* game, int imageID, int x, int y);

    ///  Default constructor (disabled)
    CTowerButton() = delete;

    /// destructor 
    ~CTowerButton() {}

    virtual void Draw(Gdiplus::Graphics* graphics);


    virtual bool HitTest(int x, int y);

private:

    /// ptr to the game we are in
    CGame* mGame = nullptr;

    /// ptr to the level set to nullptr because the level doesnt matter for the buttons
    CLevel* mLevel = nullptr;

    /// the image id for this button
    int mImageID = 0;

    /// Button's x location
    int mButtonX = 0;
    
    /// Button's y location
    int mButtonY = 0;


};

