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


    /// This will return true if the current tower has Dr. Owen on it
    /// \return true if this tower has dr owen on it
    bool HasDrOwen() const { return mHasDrOwen; }

    virtual bool Place();

    /// A setter for Dr Owen.
    /// \param HasDrOwen this should be true if this tower now has Dr. Owen
    void SetDrOwen(bool HasDrOwen) { mHasDrOwen = HasDrOwen; }

    void Fire();

    /// owen tower image id number
    const int TowerOwenImageID = 450;

    /// tower image filename
    const std::wstring TowerOwenImageName = L"images/blue-balloon.png";


private:

    /// This boolean is true if this tower actually has Dr. Owen on it
    bool mHasDrOwen = true;

    /// The current angle for which projectiles are fired (in degrees)
    double mFiringAngle = 180;

    /// Time in between each time the tower shoots ring in seconds
    double mTimeBetweenShots = 0.5; 

    /// Time till the ring can fire after level has began in seconds
    double mTimeTillFire = 0;

    /// the range that Dr. Owen can see balloons in (pixels)
    double mBalloonTargetRange = 200;

    /// the level that this tower is in
    CLevel* mLevel;

};

