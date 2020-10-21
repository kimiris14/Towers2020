#include "pch.h"
#include "Game.h"
#include "Level.h"
#include "Item.h"
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Testing
{
	/// road rn filename
	const std::wstring roadEWImageName = L"images/roadEW.png";
	/// grass 1 filename
	const std::wstring grass1ImageName = L"images/grass1.png";
	/// trees 2 filename
	const std::wstring trees2ImageName = L"images/trees2.png";
	/// house 1 filename
	const std::wstring house1ImageName = L"images/house1.png";

	/// road type 
	const std::wstring roadType = L"EW";

	/// grass type
	const std::wstring grassType = L"open";

	/// house type
	const std::wstring houseType = L"house";

	/// trees type
	const std::wstring treesType = L"trees";

	/// road ew id number
	const int roadEWID = 1;
	/// grass 1 id number
	const int grass1ID = 7;
	/// trees2 id number
	const int trees2ID = 19;
	/// house1 id number
	const int house1ID = 11;

	/// The basic level for testing
	const std::wstring baseLevel = L"levels/level0.xml";

	/** Mock class for testing CTile */
	class CTileMock : public CItemTile
	{
	public:

		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param game, the game this item is a part of
		* \param imageID The image id for this item
		*/
		CTileMock(CLevel* level, CGame* game, int imageID, std::wstring type)
			: CItemTile(level, game, imageID)
		{
			game->AddImage(house1ID, house1ImageName); 
			game->AddImage(grass1ID, grass1ImageName);
			game->AddImage(trees2ID, trees2ImageName);

			if (type == L"open")
			{
				this->SetOpen(true);
			}

			if (type == L"house" || type == L"trees")
			{
				this->SetOpen(false);
			}
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};

	/** Mock class for testing CTileRoad */
	class CTileRoadMock : public CItemTileRoad
	{
	public:

		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param game, the gamge this item is a part of
		* \param imageID The image id for this item
		* \param roadType, the road type for this tile
		*/
		CTileRoadMock(CLevel* level, CGame* game, int imageID, std::wstring roadType)
			: CItemTileRoad(level, game, imageID, roadType)
		{
			game->AddImage(roadEWID, roadEWImageName);

			this->SetOpen(false);
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};

	TEST_CLASS(TileTest)
	{
	public:


		TEST_METHOD(SetLocationTests)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CTileRoadMock road(&level, &game, roadEWID, roadType);
			CTileMock house(&level, &game, house1ID, houseType);
			CTileMock grass(&level, &game, grass1ID, grassType);
			CTileMock trees(&level, &game, trees2ID, treesType);

			road.SetGridLocation(100, 200);
			house.SetGridLocation(110, 300);
			grass.SetGridLocation(200, 100);
			trees.SetGridLocation(300, 200);

			Assert::AreEqual(road.GetGridX(), 100);
			Assert::AreEqual(road.GetGridY(), 200);
			Assert::AreEqual(house.GetGridX(), 110);
			Assert::AreEqual(house.GetGridY(), 300);
			Assert::AreEqual(grass.GetGridX(), 200);
			Assert::AreEqual(grass.GetGridY(), 100);
			Assert::AreEqual(trees.GetGridX(), 300);
			Assert::AreEqual(trees.GetGridY(), 200);
		}

		TEST_METHOD(IsOpenTests)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CTileRoadMock road(&level, &game, roadEWID, roadType);
			CTileMock house(&level, &game, house1ID, houseType);
			CTileMock grass(&level, &game, grass1ID, grassType);
			CTileMock trees(&level, &game, trees2ID, treesType);

			Assert::AreEqual(road.IsOpen(), false);
			Assert::AreEqual(trees.IsOpen(), false);
			Assert::AreEqual(house.IsOpen(), false);
			Assert::AreEqual(grass.IsOpen(), true);
		}
	};
}