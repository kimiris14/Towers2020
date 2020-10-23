/**
 * \file TowerOwen.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "TowerOwen.h"
#include "ImageMap.h"
#include "ProjectileOwen.h"
#include "ItemVisitorFindNearestBalloon.h"
#include "TowerOwenCounter.h"
#include "ItemBalloon.h"
#include "Game.h"
#include <math.h>

using namespace std;
using namespace Gdiplus;

/// Constant for Pi
const double Pi = 3.14159265358979323846;

/**
* Constructor
* \param level The level object that this item is a part of
* \param game The Game this item is a member of
*/
CTowerOwen::CTowerOwen(CLevel* level, CGame* game)
    : CTower(level, game, TowerOwenImageID), mLevel(level)
{
    // the image ID is not properly set in the CTower constructor because it is
    // not yet initialized. This fixes that
    SetImageID(TowerOwenImageID);

    game->AddImage(TowerOwenImageID, TowerOwenImageName);
    game->AddImage(DrOwenImageID, DrOwenImageName);

    mTimeTillFire = mTimeBetweenShots;
}

/** Handle updates for owen projectiles
* \param elapsed The time since the last update
*/
void CTowerOwen::Update(double elapsed)
{
    if (GetLevel()->IsActive())
    {
        mTimeTillFire -= elapsed;
        if (mTimeTillFire <= 0)
        {
            // reset the timer and shoot the owen projectiles
            mTimeTillFire += mTimeBetweenShots;

            // only fire if this tower has Dr Owen sitting on it
            if (mHasDrOwen)
                Fire();
        }

    }

}

/// Draw the Dr. Owen tower, then Dr. Owen if appropriate
/// \graphics The gdiplus graphics context to draw on
void CTowerOwen::Draw(Gdiplus::Graphics* graphics)
{
    CItem::Draw(graphics);

    shared_ptr<Bitmap> itemBitmap = GetGame()->GetImage(DrOwenImageID);

    if (itemBitmap != nullptr) {
        double wid = itemBitmap->GetWidth();
        double hit = itemBitmap->GetHeight();

        graphics->DrawImage(itemBitmap.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)itemBitmap->GetWidth(), (float)itemBitmap->GetHeight());
    }
}

/**
* Fire a new owen projectiles and place it into the level
*/
void CTowerOwen::Fire()
{

    // find the nearest balloon
    CItemVisitorFindNearestBalloon visitor((int)GetX(), (int)GetY(), mBalloonTargetRange);
    GetLevel()->Accept(&visitor);
    CItemBalloon* balloon = visitor.GetNearestBallon();

    // if there was no nearest balloon in range, then we aren't going to fire.
    if (balloon == nullptr)
        return;

    // update the firing angle so that it's pointed at the nearest balloon
    auto dX = balloon->GetX() - GetX();
    auto dY = balloon->GetY() - GetY();

    mFiringAngle = atan(dY / dX) * (180 / Pi);

    // this is necessary because inverse tangent only gives us half of the required range
    if (dX < 0) {
        mFiringAngle = mFiringAngle + 180;
    }

    auto bit = make_shared<CProjectileOwen>(GetLevel(), GetGame(), (int)GetX(), (int)GetY(), mFiringAngle);
    GetLevel()->AddDeferred(bit);
}

/**
* Keeps track of the number of times an owen tower was successfully placed and
* updates the time until fire accordingly
* \return true if the bomb was placed successfully, false otherwise
*/
bool CTowerOwen::Place()
{
    // upcall
    bool successful = CTower::Place();

    // count number of bombs placed using a visitor
    if (successful)
    {
        // only visit if it was placed successfully
        CTowerOwenCounter visitor;
        mLevel->Accept(&visitor);
        int numOwensPlaced = visitor.GetNumOwens();
        if (numOwensPlaced > 1)
        {
            this->SetDrOwen(false);
        }
        return true;
    }

    else
    {
        return false;
    }
}