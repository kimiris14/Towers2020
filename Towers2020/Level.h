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

	void Draw(CGame *game, Gdiplus::Graphics* graphics);

	void CLevel::Add(std::shared_ptr<CItem> item);

	void Update(double elapsed);

	void Accept(CItemVisitor* visitor);


private:

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

	/// The game object that this item belongs to
	CGame* mGame;

	/// the number of tiles in the x-direction
	int mLevelWidth = 16;

	/// the number of tiles in the y-direction
	int mLevelHeight = 16;

	/// The tile index of the starting tile
	int mStartingX = 0;

	/// The tile index of the starting tile
	int mStartingY = 0;

};

