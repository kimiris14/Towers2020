/**
 * \file TowerButton.h
 *
 * \author PaulaRed
 *
 * Class for the button images in the game pallette
 */
#pragma once
class CGame;

/**
* Class that places images of the tower buttons in the game palette
*/
class CTowerButton
{
public:

    CTowerButton(CGame* game);

    ///  Default constructor (disabled)
    CTowerButton() = delete;

    /// destructor 
    ~CTowerButton() {}


    void Draw(Gdiplus::Graphics* graphics);


    virtual bool HitTest(int x, int y);

private:

    /// ptr to the game we are in
    CGame* mGame = nullptr;

    /// dart tower x location
    int dartButtonX = 1090;

    /// dart tower y location
    int dartButtonY = 300;

    /// bomb tower x location
    int bombButtonX = 1090;

    /// bomb tower y location
    int bombButtonY = 400;

    /// ring tower x location
    int ringButtonX = 1090;

    /// ring tower y location
    int ringButtonY = 400;

};

