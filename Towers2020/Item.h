/**
 * \file Item.h
 *
 * \author PaulaRed
 *
 * Base class for all items on the board
 */


#pragma once

#include <string>
#include <memory>
#include "GameField.h"
#include "ImageMap.h"
#include "XmlNode.h"

using namespace xmlnode;

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
	CItem::CItem(CGame *game, CGameField *field, const std::wstring& imageID) 
		: mGame(game), mField(field), mImageID(imageID) {}


	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;


	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void Draw(Gdiplus::Graphics* graphics);

	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);


	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

protected:

	void SetImage(const std::wstring& imageID, const std::wstring& imageFile);
	
	/** Getter for mGame for derived classes
	* \returns pointer to the game object */
	CGame* GetGame() const { return mGame; }


	/** Getter for the image ID
	* \returns the image ID */
	const std::wstring& GetImageID() const { return mImageID; }

private:

	double mX = 0;  ///< x location on the board (in pixels)
	double mY = 0;  ///< y location on the board (in pixels)

	/// The image ID for the image that represents this Item
	const std::wstring& mImageID;

	/// The field that this item is a part of
	CGameField* mField;

	/// The game that this item is a part of
	CGame* mGame;
};

