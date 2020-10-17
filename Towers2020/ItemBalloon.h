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
    /// \returns mTvalue The balloon's t value
    double GetT() const { return mTValue; }

    /// Function to set the balloon's t value
    /// \param newT The balloon's new t value
    void SetT(double newT) { mTValue = newT; }

    //Add Pop definition here

    /** Test this item to see if it has been clicked on
    * \param x X location on the aquarium to test
    * \param y Y location on the aquarium to test
    * \return always false - balloons can not be clicked on */
    virtual bool HitTest(int x, int y) override { return false; }

    /// Balloon class version of the time update
    /// \param elapsed The number of seconds elapsed since last draw
    virtual void Update(double elapsed) { mTValue = mTValue + mBalloonSpeed * elapsed; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloon(this); }


private:

    /// Balloon speed in tiles per second (each tile is 64px, so this is equivalent to 128px/s)
    double mBalloonSpeed = 2.0;

    /// The balloon's t value
    double mTValue = 0.0;
};

