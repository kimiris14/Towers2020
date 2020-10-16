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
class CProjectileRing;
class CProjectileExplosion;
class CProjectileDart;


/** Tile visitor base class */
class CItemVisitor
{
public:
    /// destructor 
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

    /** Visit a CProjectileRing object
    * \param ring Ring projectile we are visiting */
    virtual void VisitRing(CProjectileRing* ring) {}

    /** Visit a CProjectileExplosion object
    * \param explosion Explosion projectile we are visiting */
    virtual void VisitExplosion(CProjectileExplosion* explosion) {}

    /** Visit a CProjectileDart object
     * \param dart Dart projectile we are visiting */
    virtual void VisitDart(CProjectileDart* dart) {}
};