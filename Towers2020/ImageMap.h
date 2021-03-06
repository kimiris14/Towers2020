/**
 * \file ImageMap.h
 *
 * \author PaulaRed
 *
 * The definition of an image map class, which will store all of the game's bitmap
 */

#pragma once

#include <unordered_map>
#include <map>
#include <string>
#include <memory>

/**
 * A class to store game images, so that they are only loaded once.
 */
class CImageMap
{
public:

	CImageMap();

	bool AddImage(std::wstring imageID, std::wstring imageFileName);

	std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring imageID);

	/**
	 * Get the size of the image map
	 * \returns The size of the map
	 */
	size_t GetSize() { return mImageMap.size(); }

private:

	/// This is the underlying data structure for this class. The mImageMap hashes image IDs
	/// stores the associated bitmap object.
	std::map<std::wstring, std::shared_ptr<Gdiplus::Bitmap>> mImageMap;
};

