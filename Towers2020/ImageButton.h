/**
 * \file ImageButton.h
 *
 * \author PaulaRed
 *
 * Class for the button images in the game pallette
 */
#pragma once
#include "Item.h"

class CGame;

/**
* Class that places images of the tower buttons in the game palette
*/
class CImageButton : public CItem
{
public:

    CImageButton(CGame* game, int imageID, int x, int y);

    ///  Default constructor (disabled)
    CImageButton() = delete;

    /// destructor 
    ~CImageButton() {}

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitButton(this); }


private:



};

