/**
 * \file GamePallette.h
 *
 * \author PaulaRed
 *
 * Game Pallette class that holds scoring mechanisms and draggable towers
 */

#pragma once
#include <vector>
#include <memory>

class CGame;
class CImageButton;
class CGoButton;

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

    std::shared_ptr<CTower> OnLButtonDown(int x, int y);

    /// Increment the score by the amount passed into this function
    /// \param increment The amount to increment the score by
    void IncrementScore(int increment = 1) { mScore = mScore + increment; }

    /// Decrement the score by the amount passed into this function
    /// \param decrement The amount to decrement the score by
    void DecrementScore(int decrement = 1) { mScore = mScore - decrement; }

    /// The size in px of the score string display
    const static int ScoreStringSize = 60;

    /// The size in px of the actual score display
    const static int ScoreSize = 80;

    /// The width of the game palette in pixels
    const static int PaletteWidth = 200;

private:

    
	/// The current score in the game
	int mScore = 0;

	/// Number of bombs laid in the game
	int mBombsLaid = 0;

    /// nullptr to the game
    CGame* mGame = nullptr;

    /// a shared ptr to the dart tower button
    std::shared_ptr<CImageButton> mDartTowerButton = nullptr;

    /// a shared ptr to the ring tower button
    std::shared_ptr<CImageButton> mRingTowerButton = nullptr;

    /// a shared ptr to the bomb tower button
    std::shared_ptr<CImageButton> mBombTowerButton = nullptr;

    /// a shared ptr to the owen tower button
    std::shared_ptr<CImageButton> mOwenTowerButton = nullptr; 

    /// a shared ptr to the go button
    std::shared_ptr<CGoButton> mGoButton = nullptr;


};

