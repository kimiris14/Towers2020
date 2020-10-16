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
#include "ImageMap.h"
#include "XmlNode.h"
#include "ItemVisitor.h"

using namespace xmlnode;

class CGame;
class CLevel;

/**
 * A class that will store all of the game's images
 */
class CItem
{
public:

	virtual ~CItem() {}

	/// Default constructor (disabled)
	CItem() = delete;

	CItem::CItem(CLevel* level, CGame* game, int imageID);


	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;


	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void Draw(Gdiplus::Graphics* graphics);

	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/** Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);

	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Base class version of the time update
	/// \param elapsed The number of seconds elapsed since last draw
	virtual void Update(double elapsed) {}

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) = 0;

protected:
	
	/** Getter for mLevel for derived classes
	* \returns pointer to the level object */
	CLevel* GetLevel() const { return mLevel; }

	/** Getter for mGame for derived classes
	* \returns pointer to the game object */
	CGame* GetGame() const { return mGame; }


	/** Getter for the image ID
	* \returns the image ID */
	int GetImageID() const { return mImageID; }

private:

	double mX = 0;  ///< x location on the board (in pixels)
	double mY = 0;  ///< y location on the board (in pixels)

	/// The image ID for the image that represents this Item
	int mImageID = 0;

	/// The level that this item is a part of
	CLevel* mLevel = nullptr;

	/// The game that this item is a part of
	CGame* mGame = nullptr;
};

