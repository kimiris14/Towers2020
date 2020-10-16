/**
 * \file Projectile.h
 *
 * \author PaulaRed
 *
 * Class for a projectile that shoots out of a tower.
 */

#pragma once
#include "Item.h"
#include "ImageMap.h"

/**
 * Projectile base class for darts, rings, and bombs
 */
class CProjectile : public CItem
{
public:
	/// Default constructor (disabled)
	CProjectile() = delete;

	/**
	* Constructor
	* \param level A pointer to the level object that this item belongs to
	* \param game A pointer to the game object that this item belongs to
	* \param imageID The image ID for this object
	*/
	CProjectile(CLevel* level, CGame* game, int imageID) :
			CItem(level, game, imageID) {}

	/// Destructor
	virtual ~CProjectile() {}

	/// Copy constructor (disabled)
	CProjectile(const CProjectile&) = delete;

	/// Draw the item
	/// \param graphics The GDI+ graphics context to draw on
	virtual void Draw(Gdiplus::Graphics* graphics) override;


	virtual void SetLocation(double x, double y) override;

	// Handle updates for animation
	// \param elapsed The time since the last update
	//virtual void Update(double elapsed) {}

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { }

private:
	/// Check to see if corresponding tower has been placed
	bool mIsTowerPlaced = false; 
	
	/// Delay time before fire
	double mTimeTillFire = 5;
};

