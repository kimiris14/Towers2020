/**
 * \file TowerRing.h
 *
 * \author PaulaRed
 *
 * Class for a ring tower
 */


#pragma once
#include "Tower.h"
#include "ItemVisitor.h"

/**
 * Class for a ring tower
 */
class CTowerRing :
    public CTower
{
public:

    CTowerRing(CLevel* level, CGame* game);

    ///  Default constructor (disabled)
    CTowerRing() = delete;

    ///  Copy constructor (disabled)
    CTowerRing(const CTowerRing&) = delete;

    /// destructor
    ~CTowerRing() {}

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerRing(this); }

    virtual void Update(double elapsed) override;

    void Fire();

    /// ring tower id number
    const int TowerRingImageID = 422;

private:


    /// tower image filename
    const std::wstring TowerRingImageName = L"images/tower-rings.png";

    /// Time in between each time the tower shoots ring in seconds
    double mTimeBetweenShots = 5;

    /// Time till the ring can fire after level has began in seconds
    double mTimeTillFire = 5;


    /// <summary>
    /// Spawn time for ring to show in window in seconds
    /// </summary>
    double mRingSpawnTime = 0;
};

