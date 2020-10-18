/**
 * \file ItemVisitorFindTower.h
 *
 * \author PaulaRed
 *
 * Item visitor to find a tower at a given index
 */


#pragma once

#include "ItemVisitor.h"

 // Forward references to all item types
class CTower;
class CTowerDart;
class CTowerRing;

/** Tower visitor class */
class CItemVisitorFindTower : public CItemVisitor
{
public:

    CItemVisitorFindTower() = delete;

    /** Constructor
     * \param x The target X pixel value to find
     * \param y The target Y pixel value to find
     */
    CItemVisitorFindTower(int x, int y) : mTargetX(x), mTargetY(y) {}

    virtual ~CItemVisitorFindTower() {}


    virtual void VisitTower(CTower* tower);
    virtual void VisitTowerDart(CTowerDart* tower);
    virtual void VisitTowerRing(CTowerRing* ringtower);

    /** Getter for the road tile that was found (if at all)
    * \returns A pointer to the found tile */
    CTower* GetTower() { return mTower; }

private:

    /// The target X index we are looking for
    const int mTargetX;

    /// The target Y index we are looking for
    const int mTargetY;

    /// If we find a road tile at the given index, this pointer will update
    /// to point to the road tile that was found
    CTower* mTower = nullptr;

};