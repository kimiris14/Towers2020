#include "pch.h"
#include "Game.h"
#include "Level.h"
#include "Item.h"
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include "ItemVisitorFindRoad.h"
#include "ItemVisitorFindTile.h"
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

	TEST_CLASS(CTileTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		TEST_METHOD(TestSetLocation)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CTileRoadMock road(&level, &game, roadEWID, roadType);
			CTileMock house(&level, &game, house1ID, houseType);
			CTileMock grass(&level, &game, grass1ID, grassType);
			CTileMock trees(&level, &game, trees2ID, treesType);

			road.SetGridLocation(1, 2);
			house.SetGridLocation(1, 3);
			grass.SetGridLocation(2, 1);
			trees.SetGridLocation(3, 2);

			Assert::AreEqual(road.GetGridX(), 1);
			Assert::AreEqual(road.GetGridY(), 2);
			Assert::AreEqual(house.GetGridX(), 1);
			Assert::AreEqual(house.GetGridY(), 3);
			Assert::AreEqual(grass.GetGridX(), 2);
			Assert::AreEqual(grass.GetGridY(), 1);
			Assert::AreEqual(trees.GetGridX(), 3);
			Assert::AreEqual(trees.GetGridY(), 2);
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

		TEST_METHOD(TestLevelTileLoading)
		{
			// this loads level zero
			CGame game;
			CLevel level(&game, baseLevel);

			// normal grass tile
			CItemVisitorFindTile visitor1(0, 8);
			level.Accept(&visitor1);
			auto tile = visitor1.GetTile();
			Assert::AreEqual(tile->GetGridX(), 0);
			Assert::AreEqual(tile->GetGridY(), 8);
			Assert::AreEqual(tile->GetImageID(), 7);
			Assert::IsTrue(tile->IsOpen());

			// find a south/east road tile
			CItemVisitorFindRoad visitor2(4, 4);
			level.Accept(&visitor2);
			auto tile2 = visitor2.GetRoad();
			Assert::AreEqual(tile2->GetGridX(), 4);
			Assert::AreEqual(tile2->GetGridY(), 4);
			Assert::AreEqual(tile2->GetImageID(), 3);
			Assert::IsFalse(tile2->IsOpen());
		}
	};
}