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

	CLevel(CGame* game) : mGame(game) {}

	void CLevel::Load(const std::wstring& filename);

	void CLevel::Clear();

	void Draw(Gdiplus::Graphics* graphics);


private:

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

	CGame* mGame;

};

