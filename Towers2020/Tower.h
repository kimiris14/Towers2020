/**
 * \file Tower.h
 *
 * \author PaulaRed
 *
 * Tower base class for the dart tower, radius tower, bomb tower, and owen tower
 */

#pragma once
#include "Item.h"



/**
 * A base class for all towers
 */
class CTower : public CItem
{
public:
	

	/**
	* Constructor
	* \param level A pointer to the level object that this item belongs to
	* \param game A pointer to the game object that this item belongs to
	* \param imageID The image ID for this object
	*/
	CTower(CLevel* level, CGame* game, int imageID) :
		CItem(level, game, imageID) {}

	/// Default constructor (disabled)
	CTower() = delete;

	///  Copy constructor (disabled)
	CTower(const CTower&) = delete;

	/// destructor 
	~CTower() {}

	/// Draw the item
	/// \param game A pointer to the game object that this item belongs to
	/// \param graphics The GDI+ graphics context to draw on
	virtual void Draw(CGame* game, Gdiplus::Graphics* graphics) override;

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) override;

	/// Accept a visitor
	/// \param visitor The visitor we accept 
	virtual void Accept(CItemVisitor* visitor) override { }

private:

	/// The time until the next fire of projectiles
	int mTimeTilFire = 0;  
};
