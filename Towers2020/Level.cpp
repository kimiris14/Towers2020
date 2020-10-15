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
* Constructor
* \param game The game object that this level belongs to
* \param filename The filename of the XML level definition file for this level
*/
CLevel::CLevel(CGame* game, std::wstring filename) : mGame(game) {
    Load(filename);
}

/**
 * Load the game level from a .xml file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * \param filename The filename of the file to load the level from.
 */
void CLevel::Load(std::wstring filename)
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

            // this is where we get the items
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"items")
            {
                for (auto itemNode : node->GetChildren())
                {
                    XmlItem(itemNode);
                }
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
 * \param game A pointer to the game object that holds graphics information
 * \param graphics The graphics context to draw on
 */
void CLevel::Draw(CGame *game, Gdiplus::Graphics* graphics)
{
    for (auto item : mItems) {
        item->Draw(game, graphics);
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
    wstring type = node->GetName();

    // Get the image ID attribute value
    auto imageIDString = node->GetAttributeValue(L"id", L"");
    int imageID = stoi(imageIDString.substr(1));  // removes the leading "i"


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
        item->XmlLoad(node);

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