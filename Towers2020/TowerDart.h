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

private:

    /// tower image filename
    const std::wstring TowerImageName = L"images/tower8.png";

    /// dart id number
    const int TowerImageID = 420; //not yet assigned
};


