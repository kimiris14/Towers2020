/**
 * \file GamePallette.h
 *
 * \author PaulaRed
 *
 * Game Pallette class that holds scoring mechanisms and draggable towers
 */

#pragma once

class CGame;

/**
 * Game pallette class that holds scoring mechanisms and draggable towers
 */
class CGamePallette
{
public:

    CGamePallette(CGame* gameD);

    ///  Default constructor (disabled)
    CGamePallette() = delete;

    ///  Copy constructor (disabled)
    CGamePallette(const CGamePallette&) = delete;

    /// destructor
    ~CGamePallette() {}

	void Draw(Gdiplus::Graphics* graphics);

private:
	/// The current score in the game
	int mScore = 0;

	/// Number of bombs laid in the game
	int mBombsLaid = 0;

    /// nullptr to the game
    CGame* mGame = nullptr;

	
};

