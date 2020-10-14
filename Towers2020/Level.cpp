/**
* \file Level.cpp
*
* \author PaulaRed
*
* Class that represents a level
*/

#include "pch.h"
#include "Level.h"
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include<memory>
#include<vector>

using namespace std;
using namespace xmlnode;

/**
 * Load the game level from a .xml XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the aquarium from.
 */
void CLevel::Load(const std::wstring& filename)
{

    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();

        // Traverse the children of the root
        // node of the XML document in memory!!!!
        for (auto node : root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                XmlItem(node);
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
void CLevel::Clear()
{
    mItems.clear();
}




/**
 * Draws all of the items in this level
 * \param graphics
 */
void CLevel::Draw(Gdiplus::Graphics* graphics)
{
    for (auto item : mItems) {
        item->Draw(graphics);
    }
}


/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{

    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    wstring type = node->GetAttributeValue(L"type", L"");
    auto imageID = node->GetAttributeValue(L"id", L"");

    if (type == L"open")
    {
        item = make_shared<CItemTile>(this, mGame, imageID);
    }

    if (type == L"road")
    {
        item = make_shared<CItemTileRoad>(this, mGame, imageID);
    }

    if (item != nullptr)
    {
        Add(item);
    }

}

/**
* Add an item to the level
* \param item The item we are adding
*/
void CLevel::Add(shared_ptr<CItem> item)
{
    mItems.push_back(item);
}