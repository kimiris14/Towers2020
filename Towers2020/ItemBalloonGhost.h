/**
 * \file ItemBalloonGhost.h
 *
 * \author Dave Yonkers
 *
 * A class for a floating ghost balloon
 */

#pragma once
#include "ItemBalloon.h"
#include "ItemVisitor.h"
#include <string>


/**
 * The definition of the ghost balloon class.
 * 
 * The ghost balloon is a balloon that floats randomly around level 3, and 
 * is worth many, many points
 */
class CItemBalloonGhost : public CItemBalloon
{
public:

    CItemBalloonGhost(CLevel* level, CGame* game);

    ///  Default constructor (disabled)
    CItemBalloonGhost() = delete;

    ///  Copy constructor (disabled)
    CItemBalloonGhost(const CItemBalloon&) = delete;

    /// Default Destructor
    ~CItemBalloonGhost() {}

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloonGhost(this); }

private:

    /// The image for the ghost balloon
    const std::wstring GhostImage = L"images/ghost-balloon.png";

    /// The image ID for the ghost balloon
    const static int GhostImageID = 737;
};

