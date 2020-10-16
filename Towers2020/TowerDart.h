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

class CTowerDart :
    public CTower
{
public:
    /**
    * Constructor
    * \param level A pointer to the level object that this item belongs to
    * \param game A pointer to the game object that this item belongs to
    * \param imageID The image ID for this object
    */
    CTowerDart(CLevel* level, int imageID);

    ///  Default constructor (disabled)
    CTowerDart() = delete;

    ///  Copy constructor (disabled)
    CTowerDart(const CTowerDart&) = delete;

    /// destructor
    ~CTowerDart() {}

    /** Accept a visitor
     * \param visitor The visitor we accept */
    //virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRoad(this); }

    /// Draw the item
    /// \param game A pointer to the game object that this item belongs to
    /// \param graphics The GDI+ graphics context to draw on
    virtual void Draw(CGame* game, Gdiplus::Graphics* graphics) override;

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    virtual void SetLocation(double x, double y) override;
};


