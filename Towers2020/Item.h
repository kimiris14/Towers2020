/**
 * \file Item.h
 *
 * \author PaulaRed
 *
 * Base class for all items on the board
 */


#pragma once

#include <string>
#include "GameField.h"

class CGame;

/**
 * A class that will store all of the game's images
 */
class CItem
{
public:

	virtual ~CItem() {}

	/// Default constructor (disabled)
	CItem() = delete;

	/**
	* Constructor
	* \param field The field this item is a member of
	* \param imageID The image ID for this object
	*/
	CItem::CItem(CGame *game, CGameField *field, const std::wstring& imageID) : mField(field), mImageID(imageID) {}


	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;


	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void Draw(Gdiplus::Graphics* graphics);


	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }


private:

	double mX;  ///< x location on the board (in pixels)
	double mY;  ///< y location on the board (in pixels)

	/// The image ID for the image that represents this Item
	const std::wstring& mImageID;


	/// The field that this item is a part of
	CGameField* mField;

	/// The game that this item is a part of
	CGame* mGame;
};

