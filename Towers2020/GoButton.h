/**
 * \file GoButton.h
 *
 * \author PaulaRed
 *
 * Class for the go button
 */
#pragma once

#include "ImageButton.h"

class CGame;

/**
* Class that represents the go button
*/
class CGoButton 
	: public CImageButton
{
public:

	CGoButton(CGame* game, int x, int y);

};

