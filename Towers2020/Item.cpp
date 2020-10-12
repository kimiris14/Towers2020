/**
 * \file Item.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"
#include "GameField.h"


using namespace std;
using namespace Gdiplus;


/**
* Draw the item
* \param graphics The graphics context to draw on
*/
void CItem::Draw(Gdiplus::Graphics* graphics)
{

    // Commented out until CGame support is added for image mapping.

    /*
    unique_ptr<Bitmap> itemBitmap = mGame.GetImage(mImageID);

    double wid = itemBitmap->GetWidth();
    double hit = itemBitmap->GetHeight();

    graphics->DrawImage(itemBitmap.get(),
        float(GetX() - wid / 2), float(GetY() - hit / 2),
        (float)mItemBitmap->GetWidth(), (float)mItemBitmap->GetHeight());
    */
}


/**
* Adds an image to the game
* \param imageID The ID for this image
* \param imageFile The file that contains the actual image data
*/
void CItem::SetImage(const std::wstring& imageID, const std::wstring& imageFile)
{
    mGame->AddImage(imageID, imageFile);
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