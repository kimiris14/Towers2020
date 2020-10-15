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

	/**
	* Constructor
	* \param level A pointer to the level object that this item belongs to
	* \param game A pointer to the game object that this item belongs to
	* \param imageID The image ID for this object
	*/
	CItem::CItem(CLevel *level, CGame *game, int imageID) 
		: mLevel(level), mGame(game), mImageID(imageID) {}


	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;


	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual void Draw(CGame *game, Gdiplus::Graphics* graphics);

	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

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

protected:

	void SetImage(int imageID, std::wstring imageFile);
	
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
	int mImageID;

	/// The level that this item is a part of
	CLevel* mLevel;

	/// The game that this item is a part of
	CGame* mGame;
};

