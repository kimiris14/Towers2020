#include "pch.h"
#include "ImageMap.h"
#include <memory>
#include <string>


using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CImageMap::CImageMap()
{
}

/**
 * Adds a bitmap to the mImageMap and shows an error message box if appropriate
 * \param imageID The ID to associate with this image
 * \param imageFileName The file for the image to load 
 * \returns true if successful, false if failure
 */
bool CImageMap::AddImage(std::wstring imageID, std::wstring imageFileName)
{

    // if the image ID is already in the map, do not load it again
    if (mImageMap.find(imageID) != mImageMap.end())
        return true;

    bool success = true;

    // load the image into a bitmap
    shared_ptr<Bitmap> bitmap = shared_ptr<Bitmap>(Bitmap::FromFile(imageFileName.c_str()));
    if (bitmap->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += imageFileName;
        AfxMessageBox(msg.c_str());
        success = false;
    }
    mImageMap[imageID] = bitmap;

    return success;
}


/**
 * Gets the Gdiplus bitmap for the image associated with the input ID
 * \param imageID The ID od the image to find the bitmap for
 * \returns A shared_ptr to the bitmap if successful
 */
std::shared_ptr<Gdiplus::Bitmap> CImageMap::GetImage(std::wstring imageID)
{

    // if the image ID is in the map, return the bitmap pointer, otherwise
    // return a nullptr.
    if (mImageMap.find(imageID) != mImageMap.end())
    {
        return mImageMap[imageID];
    }
    else
    {
        return nullptr;
    }
}
