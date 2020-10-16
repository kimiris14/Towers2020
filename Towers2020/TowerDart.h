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

    CTowerDart(CLevel* level, CGame* game, int imageID);

    ///  Default constructor (disabled)
    CTowerDart() = delete;

    ///  Copy constructor (disabled)
    CTowerDart(const CTowerDart&) = delete;

    /// destructor
    ~CTowerDart() {}

    // Accept a visitor
     // \param visitor The visitor we accept */
    //virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDart(this); }

    virtual void Draw(Gdiplus::Graphics* graphics) override;

    virtual void SetLocation(double x, double y) override;
};


