/**
 * \file ItemVisitorFindNearestBalloon.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorFindNearestBalloon.h"
#include "ItemBalloon.h"



/**
 * Constructor
 * \param y The target Y location (in pixels)
 * \param x The target X location (in pixels)
 * \param range The maximum range to accept a balloon as nearest (in pixels)
 */
CItemVisitorFindNearestBalloon::CItemVisitorFindNearestBalloon(int x, int y, double range) : mX(x), mY(y), mRange(range)
{
}


/**
 * Visit a balloon object and determine it's distance
 * \param balloon The balloon we are visiting
 */
void CItemVisitorFindNearestBalloon::VisitBalloon(CItemBalloon* balloon)
{

    // if the balloon is popped, we don't care about it
    if (balloon->IsPopped())
        return;

    // distance from the current balloon to the center of the ring
    double dist = sqrt(pow((mX - balloon->GetX()), 2) + pow((mY - balloon->GetY()), 2));

    // if the balloon is the new closeest within range...
    if ((mNearestBalloon == nullptr || dist < mBalloonDistance) && (dist <= mRange))
    {
        mBalloonDistance = dist;
        mNearestBalloon = balloon;
    }

}
