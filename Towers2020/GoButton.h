/**
 * \file GoButton.h
 *
 * \author PaulaRed
 *
 * Class for the go button
 */
#pragma once

#include "ImageButton.h"
#include <string>

class CGame;

/**
* Class that represents the go button
*/
class CGoButton 
	: public CImageButton
{
public:

	CGoButton(CGame* game, int x, int y);

	/// go button image name
	const std::wstring mGoButtonImageName = L"images/button-go.png";

	/// go button id number
	const int mGoButtonImageID = 500;
};

