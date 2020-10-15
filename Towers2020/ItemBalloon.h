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
#include "ItemVisitor.h"



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


    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloon(this); }


private:

    /// The balloon's t value
    float mTValue = 0;
};

