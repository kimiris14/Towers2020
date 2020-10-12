/**
 * \file Game.cpp
 *
 * \author PaulaRed
 */

#include "pch.h"
#include "Game.h"
#include "XmlNode.h"
#include <map>
#include <string>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/// house1 filename
const wstring houseOneImageName = L"images/house1.png";

/// house1 id number
const wstring houseOneID = L"i011";

/// house2 filename
const wstring houseTwoImageName = L"images/house2.png";

/// house2 id number
const wstring houseTwoID = L"i012";

/// house3 filename
const wstring houseThreeImageName = L"images/house3.png";

/// house3 id number
const wstring houseThreeID = L"i013";

/// house4a filename
const wstring houseFourAImageName = L"images/house4a.png";

/// house4a id number
const wstring houseFourAID = L"i014";

/// house4b filename
const wstring houseFourBImageName = L"images/house4b.png";

/// house4b id number
const wstring houseFourBID = L"i015";

/// castlea filename
const wstring castleAImageName = L"images/castlea.png";

/// castlea id number
const wstring castleAID = L"i016";

/// castleb filename
const wstring castleBImageName = L"images/castleb.png";

/// castleb id number
const wstring castleBID = L"i017";

/// trees1 filename
const wstring treesOneImageName = L"images/trees1.png";

/// trees1 id number
const wstring treesOneID = L"i018";

/// trees2 filename
const wstring treesTwoImageName = L"images/trees2.png";

/// trees2 id number
const wstring treesTwoID = L"i019";

/// trees3 filename
const wstring treesThreeImageName = L"images/trees3.png";

/// trees3 id number
const wstring treesThreeID = L"i020";

/// trees4 filename
const wstring treesFourImageName = L"images/trees4.png";

/// trees4 id number
const wstring treesFourID = L"i021";

/**
* Game constructor
* Loads the each image necessary for the game once through a map
*/
CGame::CGame()
{
    
    mImageMap.AddImage(houseOneID,   houseOneImageName);
    mImageMap.AddImage(houseTwoID,   houseTwoImageName);
    mImageMap.AddImage(houseThreeID, houseThreeImageName);
    mImageMap.AddImage(houseFourAID, houseFourAImageName);
    mImageMap.AddImage(houseFourBID, houseFourBImageName);
    mImageMap.AddImage(castleAID,    castleAImageName);
    mImageMap.AddImage(castleBID,    castleBImageName);
    mImageMap.AddImage(treesOneID,   treesOneImageName);
    mImageMap.AddImage(treesTwoID,   treesTwoImageName);
    mImageMap.AddImage(treesThreeID, treesThreeImageName);
    mImageMap.AddImage(treesFourID,  treesFourImageName);
}

/**
  * Draw the game area
  * \param graphics The GDI+ graphics context to draw on
  * \param width Width of the client window
  * \param height Height of the client window
  */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(Width);
    float scaleY = float(height) / float(Height);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - Width * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - Height * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // from here on you are drawing virtual pixels

}


/**
* Handle a click on the game area
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonDown(int x, int y)
{
    // convert the x and y clicked pixel coordinates into virtual pixel coordinates
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

}

/**
 * Save the game level as a .xml XML file.
 *
 * Open an XML file and stream the level data to it.
 *
 * \param filename The filename of the file to save the level to
 */
void CGame::Save(const std::wstring& filename)
{   //
    // Create an XML document
    //
    auto root = CXmlNode::CreateDocument(L"xml");


    // Iterate over all items and save them
    for (auto item : mItems)
    {
        item->XmlSave(root);
    }
    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Load the game level from a .xml XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the aquarium from.
 */
void CGame::Load(const std::wstring& filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();
        //
        // Traverse the children of the root
        // node of the XML document in memory
        //
        for (auto node : root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                //XmlItem(node);
            }
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Clear the game data.
 *
 * Deletes all known items in the game.
 */
void CGame::Clear()
{
    mItems.clear();
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    wstring type = node->GetAttributeValue(L"type", L"");
    if (type == L"beta")
    {
        item = make_shared<CFishBeta>(this);
    }
    if (type == L"nemo")
    {
        item = make_shared<CNemo>(this);
    }
    if (type == L"dory")
    {
        item = make_shared<CDory>(this);
    }
    if (type == L"castle")
    {
        item = make_shared<CDecorCastle>(this);
    }


    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }
}*/


