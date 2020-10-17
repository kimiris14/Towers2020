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

    CTowerButton(CGame* game, int imageID, int x, int y);

    ///  Default constructor (disabled)
    CTowerButton() = delete;

    /// destructor 
    ~CTowerButton() {}

    virtual void Draw(Gdiplus::Graphics* graphics);


    virtual bool HitTest(int x, int y);

private:

    /// ptr to the game we are in
    CGame* mGame = nullptr;

    /// the image id for this button
    int mImageID = 0;

    /// the x location for this button
    int mButtonX = 0;

    /// the y location for this button
    int mButtonY = 0;


};

