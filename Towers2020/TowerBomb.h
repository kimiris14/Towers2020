/**
* \file TowerRing.h
*
* \author PaulaRed
*
* Class for a bomb tower
*/

#pragma once
#include "Tower.h"


/**
 * Class for a bomb tower
 */
class CTowerBomb :
    public CTower
{
public:

    CTowerBomb(CLevel* level, CGame* game);

    ///  Default constructor (disabled)
    CTowerBomb() = delete;

    ///  Copy constructor (disabled)
    CTowerBomb(const CTowerBomb&) = delete;

    /// destructor
    ~CTowerBomb() {}

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerBomb(this); }

    virtual void Update(double elapsed) override;

    void Fire();

    /// ring tower id number
    const int TowerBombImageID = 424;

private:

    /// tower image filename
    const std::wstring TowerBombImageName = L"images/tower-bomb.png";

    /// Time in between each time one bomb tower shoots an explosion in seconds
    double mTimeBetweenShots = 3;

};

