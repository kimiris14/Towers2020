/**
 * \file TowerOwen.h
 *
 * \author PaulaRed
 *
 * Class for an owen tower
 */


#pragma once
#include "Tower.h"
#include "ItemVisitor.h"

/**
 * Class for an owen tower
 */
class CTowerOwen :
    public CTower
{

public:

    CTowerOwen(CLevel* level, CGame* game);

    ///  Default constructor (disabled)
    CTowerOwen() = delete;

    ///  Copy constructor (disabled)
    CTowerOwen(const CTowerOwen&) = delete;

    /// destructor
    ~CTowerOwen() {}

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerOwen(this); }

    virtual void Update(double elapsed) override;

    void Fire();

    /// owen tower image id number
    const int TowerOwenImageID = 450;

    /// tower image filename
    const std::wstring TowerOwenImageName = L"images/blue-balloon.png";


private:


    /// Time in between each time the tower shoots ring in seconds
    double mTimeBetweenShots = 0; //possibly changed later

    /// Time till the ring can fire after level has began in seconds
    double mTimeTillFire = 0; //possibly changed later
};

