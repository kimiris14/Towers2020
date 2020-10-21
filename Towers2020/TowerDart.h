/**
 * \file TowerDart.h
 *
 * \author PaulaRed
 *
 * Class for a dart tower
 */

#pragma once
#include "Tower.h"
#include "ItemVisitor.h"
#include "ProjectileDart.h"

#include <vector>

/**
 * Class for a dart tower
 */
class CTowerDart :
    public CTower
{
public:

    CTowerDart(CLevel* level, CGame* game);

    ///  Default constructor (disabled)
    CTowerDart() = delete;

    ///  Copy constructor (disabled)
    CTowerDart(const CTowerDart&) = delete;

    /// destructor
    ~CTowerDart() {}

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerDart(this); }

    virtual void Update(double elapsed) override;

    void Fire();

    /// dart id number
    const int TowerImageID = 420;

private:
    
    /// tower image filename
    const std::wstring TowerImageName = L"images/tower8.png";
    
    /// Time in between each time the tower shoots darts in seconds
    double mTimeBetweenShots = 5;

    /// The distance from the tower
    double mT = 20;

    double mSpeedX = 3.0;

    int mAngleCount = 0;
};


