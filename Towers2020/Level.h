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

	/**
	* Constructor
	* \param game The game object that this level belongs to
	*/
	CLevel(CGame* game) : mGame(game) {}

	void CLevel::Load(const std::wstring& filename);

	void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void CLevel::Clear();

	void Draw(Gdiplus::Graphics* graphics);

	void CLevel::Add(std::shared_ptr<CItem> item);


private:

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

	/// The game object that this item belongs to
	CGame* mGame;

};

