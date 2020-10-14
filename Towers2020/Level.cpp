/**
* \file Level.cpp
*
* \author PaulaRed
*
* Class that represents a level
*/

#include "pch.h"
#include "Level.h"

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
        //Clear();
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
