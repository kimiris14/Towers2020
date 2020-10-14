/**
 * \file Item.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"


using namespace std;
using namespace Gdiplus;


/**
* Draw the item
* \param graphics The graphics context to draw on
*/
void CItem::Draw(Gdiplus::Graphics* graphics)
{

    shared_ptr<Bitmap> itemBitmap = mGame->GetImageMap()->GetImage(mImageID);

    double wid = itemBitmap->GetWidth();
    double hit = itemBitmap->GetHeight();

    graphics->DrawImage(itemBitmap.get(),
        float(GetX() - wid / 2), float(GetY() - hit / 2),
        (float)itemBitmap->GetWidth(), (float)itemBitmap->GetHeight());
}


/**
* Adds an image to the game
* \param imageID The ID for this image
* \param imageFile The file that contains the actual image data
*/
void CItem::SetImage(const std::wstring& imageID, const std::wstring& imageFile)
{
    mGame->GetImageMap()->AddImage(imageID, imageFile);
}


/**
 * Save the attributes for an item node.
 *
 * This is the  base class version that saves the attributes
 * common to all items. Override this to save custom attributes
 * for specific items.
 *
 * \param node The Xml node we are saving the item from
 */
std::shared_ptr<xmlnode::CXmlNode> CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = node->AddChild(L"item");

    itemNode->SetAttribute(L"x", mX);
    itemNode->SetAttribute(L"y", mY);

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * \param node The Xml node we are loading the item from
 */
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mX = node->GetAttributeDoubleValue(L"x", 0);
    mY = node->GetAttributeDoubleValue(L"y", 0);
}



/** Test this item to see if it has been clicked on
 * \param x X location on the aquarium to test
 * \param y Y location on the aquarium to test
 * \return true if clicked on
 */
bool CItem::HitTest(int x, int y)
{

    auto itemImage = mGame->GetImageMap()->GetImage(mImageID);

    double wid = itemImage->GetWidth();
    double hit = itemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = itemImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        itemImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
}
