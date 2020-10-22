/**
 * \file ItemVisitorRingPopFinder.cpp
 *
 * \author Dave Yonkers
 */

#include "pch.h"
#include "ItemVisitorRingPopFinder.h"
#include "ItemBalloon.h"
#include <cmath>

using namespace std;


/**
 * Constructor
 * \param originX The origin of the circle's x component in pixels
 * \param originY The origin of the circle's y component in pixels
 * \param radius The radius of the circle in pixels
 * \param range The poppable range between the ring's edge and a balloon's center in pixels.
 * \param points The number of points to give per each balloon pop
 */
CItemVisitorRingPopFinder::CItemVisitorRingPopFinder(int originX, int originY, 
    double radius, double range, int points) : mOriginX(originX), mOriginY(originY), mPopPoints(points)
{

    mMinPoppingDistance = radius - range;
    mMaxPoppingDistance = radius + range;

}

/** Visit a CItemBalloon object and determine if it can be popped
* \param balloon Balloon we are visiting */
void CItemVisitorRingPopFinder::VisitBalloon(CItemBalloon* balloon)
{

    // distance from the current balloon to the center of the ring
    double dist = sqrt(  pow((mOriginX - balloon->GetX()), 2) + pow((mOriginY - balloon->GetY()), 2)  );

    if ((mMinPoppingDistance <= dist) && (dist <= mMaxPoppingDistance))
    {
        balloon->Pop(mPopPoints);
    }
}
