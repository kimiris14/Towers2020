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
#include <map>
#include "Item.h"
#include "ImageMap.h"

class CGame;
class CGamePallette;

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

	void CLevel::XmlItemDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void CLevel::Clear();

	void Draw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);

	void AddDeferred(std::shared_ptr<CItem> item);

	void Update(double elapsed);

	void Accept(CItemVisitor* visitor);

	void OnLButtonDown(int x, int y);

	/// Starts the level
	void Start() { mLevelActive = true; }

	void EscapedBalloon(std::shared_ptr<CItemBalloon> balloon);

	std::shared_ptr<CItem> PickUpTower(int x, int y);

	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Getter for the level active boolean. 
	/// Tells the caller if the current level is active
	/// \returns true if the level has been activated
	bool IsActive() const { return mLevelActive; }

	/// When an item needs to be deleted from the level, use this to remove it.
	/// It waits until all of the updates are done before removing it, otherwise
	/// there would be runtime errors
	/// \param item The item within mItems to remove.
	void RemoveItem(std::shared_ptr<CItem> item) { mItemsToDelete.push_back(item); }

	/// Getter for the level's height in grid tiles
	/// \returns the height in grid tiles
	int GetHeight() const { return mLevelHeight; }

	/// Getter for the level's width in grid tiles
	/// \returns the width in grid tiles
	int GetWidth() const { return mLevelWidth; }

	/// Getter for the level's total elapsed time
	/// <returns> the total elapsed time in seconds </returns>
	double GetElapsedTime() const { return mTotalElapsedTime; }
	/**
	* Tells us if towers can be dragged or not
	* \return true if towers can be dragged, false if not
	*/
	bool IsTitleDisplayed() { return mDisplayTitle; }

	/**Setter for the number of active balloons*/
	void DerementActiveBalloons() { mNumBalloonsActive -= 1; }

	/// A getter for the next level
	/// \returns the filename for the next level
	std::wstring GetNextLevel() { return mNextLevelFilename; }

	/// A getter for if the level is completed
	/// \returns true if the level has been completed
	bool IsCompleted() { return mLevelCompleted; }


	/// the last level
	const std::wstring LastLevel = L"3";

	/// the y location for the level title
	const Gdiplus::REAL LevelTitleY = 400;

	/// the x location for the level title
	const Gdiplus::REAL LevelStringX = 170;

private:

	/// the current level number
	std::wstring mLevelNumber;

	/// the next level to Load
	std::wstring mNextLevelNumber;

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

	/// The game object that this item belongs to
	CGame* mGame = nullptr;

	/// the number of tiles in the x-direction
	int mLevelWidth = 16;

	/// the number of tiles in the y-direction
	int mLevelHeight = 16;

	/// the spacing of each tile on the grid in pixels
	int mTileSpacing = 64;

	/// The tile index of the starting tile
	int mStartingX = 0;

	/// The tile index of the starting tile
	int mStartingY = 0;

	/// The number of balloons to spawn for this level 
	/// (this is subracted by one every time a balloon is spawned)
	int mNumBalloonsToSpawn = 30;  // project descriptions says 30

	/// we start off with 30 active balloons, this will be decremented as they 
	/// are popped or they escape
	int mNumBalloonsActive = 30;

	/// The total time that has elapsed since the last time a balloon was spawned
	double mTimeSinceSpawn = 0;

	/// The balloon spawn rate in balloons per second.
	/// 3.0476 balloons per second ~= 42px in between balloons at a 128px/s balloon speed
	double mBalloonSpawnRate = 3.0476;

	/// Holds the total elapsed time since the level started in seconds
	double mTotalElapsedTime = 0;

	/// A boolean to go from the loaded state to the active state (when to start spawning balloons)
	bool mLevelActive = false;

	/// A boolean to determine when all of the balloons are gone
	bool mLevelCompleted = false;

	/// a boolean for knowing when we display the level title
	bool mDisplayTitle = true;

	/// a boolean to keep track of if we reset the total elapsed time 
	/// had a hard time figuring out a solution without this boolean for loading the next level in update
	bool mResetTotalElapsedTime = false;

	/// level titles are displayed for two seconds
	int mDisplayTitleTime = 2;

	/// the next level to be loaded
	std::wstring mNextLevelFilename = L"";

	/// Add all items that need to be deleted to this list during updates. 
	/// Everything from this list is found and removed from mItems after
	/// each time update has completed
	std::vector<std::shared_ptr<CItem>> mItemsToDelete;

	/// The amount of points rewarded to the user per balloon pop
	int mPointsPerPop = 1;

	/// The amount of points taken away from the user when a balloon escapes (positive integer)
	int mPointsPerEscape = 1;

	/// Stores the image ID and maps it to the type of road. This is used only during loading
	std::map<int, std::wstring> mIDToRoad;

	/// Temporary mItems
	std::vector<std::shared_ptr<CItem>> mDeferredAdds;
};

