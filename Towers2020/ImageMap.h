/**
 * \file ImageMap.h
 *
 * \author PaulaRed
 *
 * The definition of an image map class, which will store all of the game's bitmap
 */

#pragma once

#include <unordered_map>
#include <string>
#include <memory>

/**
 * 
 */
class CImageMap
{
public:

	CImageMap();

	bool AddImage(std::wstring imageID, std::wstring imageFileName);

	std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring imageID);

private:

	std::unordered_map<std::wstring, std::shared_ptr<Gdiplus::Bitmap>> mImageMap;
};

