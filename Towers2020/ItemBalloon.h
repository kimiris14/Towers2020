/**
 * \file ItemBalloon.h
 *
 * \author PaulaRed
 *
 * Class for a balloon that enters the game field
 */

#pragma once
#include "Item.h"
#include "ImageMap.h"



/**
 * Class to represent a balloon in the level
 */
class CItemBalloon :
    public CItem
{
public:
    CItemBalloon(CLevel *level, CGame* game, int imageID);

    ///  Default constructor (disabled)
    CItemBalloon() = delete;

    ///  Copy constructor (disabled)
    CItemBalloon(const CItemBalloon&) = delete;

    ~CItemBalloon() {}

    /// Function to get the balloon's t value
    /// <returns> mTvalue The balloon's t value </returns>
    float CItemBalloon::GetTValue() { return mTValue; }

    //Add Pop definition here


private:

    /// The balloon's t value
    float mTValue = 0;
};

