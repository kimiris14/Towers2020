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

    virtual void Update(double elapsed) override;
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    void Pop(int score);

    /// Gets the Ghost balloon's current points multiplier
    /// \return The current points multiplier
    int GetMultiplier() const { return mMultiplier; }

private:

    /// This is the multiplier in points for popping a ghost balloon.
    /// It has to be a multiplier because different towers are worth different amounts.
    int mMultiplier = 10;

    /// The image for the ghost balloon
    const std::wstring GhostImage = L"images/ghost-balloon.png";

    /// The image ID for the ghost balloon
    const static int GhostImageID = 737;

    /// Ghost floating speed in pixels per second
    double mSpeed = 64;

    /// This will hold the time at which the special message should be shown until
    double mShowMessageUntil = 0;

    /// How long the message will show on the screen in seconds
    double mShowMessageDelay = 2.0;

    /// The special message to display when a ghost balloon is popped
    std::wstring mSpecialMessage = L"Those who know, BOO!";

    /// This value scales the sway of the balloon so that it looks more normal. It is initially
    /// generated randomly in the constructor to a value [0,1]
    double mSwayScaler = 1;

};

