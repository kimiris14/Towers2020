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


	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {mTotalElapsed += elapsed;}

	/// Getter for the projectile's total elapsed time
	/// \returns The total elapsed time since the projectile has been fired (in seconds)
	double GetTotalElapsed() const { return mTotalElapsed; }

	/// Setter for the projectile's activity status
	/// \param active If the projectile can still pop a balloon, than this value should be
	/// considered true, or active
	void SetActive(bool active) { mProjectileActive = active; }

	/// Getter for the projectile's activity status
	/// \returns True if the projectile is active, false if it is completely spent
	bool IsActive() const { return mProjectileActive; }

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitProjectile(this); }

	//virtual bool HitBalloon(CItemBalloon* balloon);

private:

	/// the total elapsed time that the projectile has been alive (in seconds)
	double mTotalElapsed = 0;

	/// A boolean to determine if the projectile is active or completely spent.
	bool mProjectileActive = true;

};

