/**
 * \file ItemBalloonGhost.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "ItemBalloonGhost.h"
#include "ItemBalloon.h"
#include "Item.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;


 /**
  * Constructor
  * \param level The level that this balloon belongs to
  * \param game The game that this balloon belongs to
  */
CItemBalloonGhost::CItemBalloonGhost(CLevel* level, CGame* game) : CItemBalloon(level, game)
{
	SetImageID(GhostImageID);
	GetGame()->AddImage(GhostImageID, GhostImage);
}

/**
 * Update the balloon
 * \param elapsed The elapsed time since the last update
 */
void CItemBalloonGhost::Update(double elapsed)
{
	if (IsActive()) 
	{
		
		auto newY = GetY() - mSpeed * elapsed;

		/// The arbirary numbers just control the way that the balloon sways
		auto newX = GetX() + 4 * sin(GetY() / (CGame::Height / 90));

		SetLocation(newX, newY);
	}

	// deactivate if the balloon is now out of bounds
	if (GetY() < 0 || GetX() < 0 || GetX() > (CGame::Width - CGamePallette::PaletteWidth))
		SetActive(false);


}


/// Draw the balloon or it's secret message
/// \graphics the Gdiplus graphics context to draw on
void CItemBalloonGhost::Draw(Gdiplus::Graphics* graphics)
{
	/// Show the special message and only if the level is not completed
	if (mShowMessageUntil > GetLevel()->GetElapsedTime() && !GetLevel()->IsCompleted()) {

		// Font 
		FontFamily fontFamily(L"Arial");

		// Font size
		Gdiplus::Font font(&fontFamily, 25, 0, UnitPixel);

		StringFormat stringFormat;

		// Center-justify each line of text.
		stringFormat.SetAlignment(StringAlignmentCenter);

		// Center the block of text (top to bottom) in the rectangle.
		stringFormat.SetLineAlignment(StringAlignmentCenter);

		SolidBrush white(Color(255, 255, 0));

		// Draw the score Value in yellow
		graphics->DrawString(mSpecialMessage.c_str(),  // String to draw
			-1,         // String length, -1 so it figures it out on its own
			&font,      // The font to use
			RectF(GetX() - 100, GetY() - 30, 200, 60),   // Draw to the center of this rectangle
			&stringFormat,
			&white);    // The brush to draw the text with
	}

	if (IsActive())
		CItemBalloon::Draw(graphics);
}


/// This function "pops" the balloon
/// \param score the number of points that should be associated with this pop
void CItemBalloonGhost::Pop(int score)
{
	mShowMessageUntil = GetLevel()->GetElapsedTime() + mShowMessageDelay;

	// this is necessary because ghost balloons aren't considered "active" by default, since they're ghosts
	GetLevel()->IncrementActiveBalloons(); 
	CItemBalloon::Pop(score);
}