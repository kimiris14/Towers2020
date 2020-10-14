/**
* \file Level.h
* 
* \author PaulaRed
* 
* Class that represents a level
*/

#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#pragma once

/**
* Class that represents a level
*/
class CLevel
{
public:
	void CLevel::Load(const std::wstring& filename);

	void CLevel::Clear();


private:

	/// All of the items to add to our game
	std::vector<std::shared_ptr<CItem> > mItems;

};

