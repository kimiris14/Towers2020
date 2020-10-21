/**
 * \file ItemBalloon.cpp
 *
 * \author PaulaRed
 */


#include "pch.h"
#include "ItemBalloon.h"
#include "ImageMap.h"
#include "Game.h"

using namespace std;


/**
* Constructor
* \param level The Level this item is a member of
* \param game The Game this item is a member of
*/
CItemBalloon::CItemBalloon(CLevel *level, CGame *game) : CItem(level,game,RedBalloonID)
{
    SetImageID(RedBalloonID);  // base it is uninitialized during the call to CItem constructor
    game->AddImage(RedBalloonID, RedBalloonImageName);
}

/**
* Draw the balloon only if it is unpopped
* \param graphics The graphics context to draw on
*/
void CItemBalloon::Draw(Gdiplus::Graphics* graphics)
{
    if (!mIsPopped)
    {
        CItem::Draw(graphics);
    }
}

/// This function "pops" the balloon
/// \param the number of points that should be associated with this pop
void CItemBalloon::Pop(int score)
{
    // the if statement is here to protect from lag causing a balloon to be popped more than once
    if (mIsPopped == false) {
        mIsPopped = true;
        GetGame()->GetPallette()->IncrementScore(score);
    }
}
