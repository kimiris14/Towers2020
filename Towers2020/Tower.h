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

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	virtual void SetLocation(double x, double y) override;

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTower(this); }

protected:
	/// The time until the next fire of projectiles
	double mTimeTillFire = 0;  
};
