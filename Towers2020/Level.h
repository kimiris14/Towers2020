/**
* \file Level.h
* 
* \author PaulaRed
* 
* Class that represents a level
*/
#pragma once


#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#include "ImageMap.h"

class CGame;

/**
* Class that represents a level
*/
class CLevel
{
public:

	CLevel() = delete;

	CLevel(CGame* game, std::wstring filename);

	void CLevel::Load(std::wstring filename);

	void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void CLevel::Clear();

	void Draw(Gdiplus::Graphics* graphics);

	void CLevel::Add(std::shared_ptr<CItem> item);

	void Update(double elapsed);

	void Accept(CItemVisitor* visitor);

	/// Starts the level
	void Start() { mLevelActive = true; }

	std::shared_ptr<Gdiplus::Bitmap> GetImage(int id);

	bool AddImage(int imageID, std::wstring imageFileName);

	void EscapedBalloon(std::shared_ptr<CItemBalloon> balloon);


private:

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

	/// The game object that this item belongs to
	CGame* mGame = nullptr;

	/// the number of tiles in the x-direction
	int mLevelWidth = 16;

	/// the number of tiles in the y-direction
	int mLevelHeight = 16;

	/// The tile index of the starting tile
	int mStartingX = 0;

	/// The tile index of the starting tile
	int mStartingY = 0;

	/// The number of balloons to spawn for this level 
	/// (this is subracted by one every time a balloon is spawned)
	int mNumBalloonsToSpawn = 30;  // project descriptions says 30

	/// The total time that has elapsed since the last time a balloon was spawned
	double mTimeSinceSpawn = 0;

	/// The balloon spawn rate in balloons per second.
	/// 3.0476 balloons per second ~= 42px in between balloons at a 128px/s balloon speed
	double mBalloonSpawnRate = 3.0476;

	/// The default balloon ID to spawn (44 is red)
	int mDefaultBalloonID = 44;

	/// Holds the total elapsed time since the level started in seconds
	double mTotalElapsedTime = 0;

	/// A boolean to go from the loaded state to the active state (when to start spawning balloons)
	bool mLevelActive = false;

	/// A boolean to determine when all of the balloons are gone
	bool mLevelCompleted = false; 

	/// Add all items that need to be deleted to this list during updates. 
	/// Everything from this list is found and removed from mItems after
	/// each time update has completed
	std::vector<std::shared_ptr<CItem>> mItemsToDelete;

};

