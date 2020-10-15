/**
 * \file ItemVisitor.h
 *
 * \author PaulaRed
 *
 * Item visitor base class.
 */


#pragma once

 // Forward references to all item types
class CItemBalloon;
class CItemTile;
class CItemTileRoad;


/** Tile visitor base class */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a CItemBalloon object
     * \param balloon Balloon we are visiting */
    virtual void VisitBalloon(CItemBalloon* balloon) {}

    /** Visit a CItemTile object
    * \param tile Tile we are visiting */
    virtual void VisitTile(CItemTile* tile) {}

    /** Visit a CItemTileRoad object
    * \param road Road we are visiting */
    virtual void VisitRoad(CItemTileRoad* road) {}

};