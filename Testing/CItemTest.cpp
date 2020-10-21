#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Level.h"
#include "Item.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/// red balloon filename
const std::wstring redBalloonImageName = L"images/red-balloon.png";

/// red balloon id number
const int redBalloonID = 44;

/// The basic level for testing
const std::wstring baseLevel = L"levels/level0.xml";


namespace Testing
{

	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:

		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param imageID The image id for this item
		*/
		CItemMock(CLevel* level, CGame* game, int imageID)
			: CItem(level, game, imageID)
		{

			game->AddImage(redBalloonID, redBalloonImageName);
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCItemConstruct)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CItemMock item(&level, &game, redBalloonID);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CGame game;
			CLevel level(&game, baseLevel);
			CItemMock item(&level, &game, redBalloonID);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemHitTest)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CItemMock item(&level, &game, redBalloonID);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			item.SetLocation(100, 200);

			// Center of the item should be a true
			Assert::IsTrue(item.HitTest(100, 200));

			// Left of the item
			Assert::IsFalse(item.HitTest(10, 200));

			// Right of the item
			Assert::IsFalse(item.HitTest(200, 200));

			// Above the item
			Assert::IsFalse(item.HitTest(100, 0));

			// Below the item
			Assert::IsFalse(item.HitTest(100, 300));

			// Of balloon transparent pixel
			Assert::IsFalse(item.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}
	};

}