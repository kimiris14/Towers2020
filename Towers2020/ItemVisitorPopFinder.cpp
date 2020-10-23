/**
 * \file ItemVisitorPopFinder.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemVisitorPopFinder.h"
#include "ItemBalloon.h"
#include <cmath>

using namespace std;


/**
 * Constructor
 * \param originX The origin of the circle's x component in pixels
 * \param originY The origin of the circle's y component in pixels
 * \param radius The radius of the circle in pixels
 * \param points The number of points to give per each balloon pop
 */
CItemVisitorPopFinder::CItemVisitorPopFinder(int originX, int originY,
    double radius, int points) : mOriginX(originX), mOriginY(originY), mPopPoints(points), mPoppingDistance(radius)
{

}

/** Visit a CItemBalloon object and determine if it can be popped
* \param balloon Balloon we are visiting */
void CItemVisitorPopFinder::VisitBalloon(CItemBalloon* balloon)
{

    // distance from the current balloon to the center of the ring
    double dist = sqrt(pow((mOriginX - balloon->GetX()), 2) + pow((mOriginY - balloon->GetY()), 2));

    // if the balloon is within popping distance, pop it
    if (dist < mPoppingDistance && !balloon->IsPopped())
    {
        balloon->Pop(mPopPoints);
        mHasPopped = true;
    }
}
