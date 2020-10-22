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
class CProjectile;
class CItem;
class CTower;
class CTowerDart;
class CTowerRing;
class CTowerBomb;
class CImageButton;


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

    /** Visit a CProjectile object
     * \param projectile The projectile we are visiting */
    virtual void VisitProjectile(CProjectile* projectile) {}

    virtual void VisitGarbage() {};

    /** Visit a CProjectileRing object
    * \param ring Ring projectile we are visiting */
    virtual void VisitRing(CProjectileRing* ring) {}

    /** Visit a CProjectileExplosion object
    * \param explosion Explosion projectile we are visiting */
    virtual void VisitExplosion(CProjectileExplosion* explosion) {}

    /** Visit a CProjectileDart object
     * \param dart Dart projectile we are visiting */
    virtual void VisitDart(CProjectileDart* dart) {}

    /** Visit a CTower object
     * \param tower Tower projectile we are visiting */
    virtual void VisitTower(CTower* tower) {}

    /** Visit a CTowerDart object
     * \param darttower The Dart Tower we are visiting */
    virtual void VisitTowerDart(CTowerDart* darttower) {}

    /** Visit a CTowerRing object
    * \param ringtower The Ring Tower we are visiting */
    virtual void VisitTowerRing(CTowerRing* ringtower) {}

    /** Visit a CTowerBomb object
    * \param bombtower The Bomb Tower we are visiting */
    virtual void VisitTowerBomb(CTowerBomb* bombtower) {}

    /** Visit a CImageButton object
     * \param button The button we are visiting */
    virtual void VisitButton(CImageButton* button) {}

};