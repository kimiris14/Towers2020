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
    CItemBalloon(CLevel *level, CGame* game);

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

    /** Test this item to see if it has been clicked on
    * \param x X location on the aquarium to test
    * \param y Y location on the aquarium to test
    * \return always false - balloons can not be clicked on */
    virtual bool HitTest(int x, int y) override { return false; }

    /// Balloon class version of the time update
    /// \param elapsed The number of seconds elapsed since last draw
    virtual void Update(double elapsed) { mTValue = mTValue + mBalloonSpeed * elapsed; }

    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloon(this); }

    virtual void Pop(int score);

    /// red balloon filename
    const std::wstring RedBalloonImageName = L"images/red-balloon.png";

    /// red balloon id number
    const int RedBalloonID = 44;

private:

    /// Balloon speed in tiles per second (each tile is 64px, so this is equivalent to 128px/s)
    double mBalloonSpeed = 2.0;

    /// The balloon's t value
    double mTValue = 0.0;

};

