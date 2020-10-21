#include "pch.h"
#include "Game.h"
#include "Level.h"
#include "ItemBalloon.h"
#include "ItemTile.h"
#include "ItemTileRoad.h"
#include "ItemVisitor.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Testing
{
	/// The basic level for testing
	const std::wstring baseLevel = L"levels/level0.xml";

	/**Mock visitor class for testing*/
	class CTestVisitor : public CItemVisitor
	{
	public:
		virtual void VisitBalloon(CItemBalloon* balloon) override { mNumBalloons++; }

		int mNumBalloons = 0;
	};


	TEST_CLASS(VisitorTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(BalloonVisitorTest)
		{
			CGame game;
			CLevel level(&game, baseLevel);

			// clear level and add balloons to the game
			level.Clear();

			auto balloon1 = std::make_shared<CItemBalloon>(&level, &game);
			auto balloon2 = std::make_shared<CItemBalloon>(&level, &game);
			auto balloon3 = std::make_shared<CItemBalloon>(&level, &game);
			auto balloon4 = std::make_shared<CItemBalloon>(&level, &game);
			
			level.Add(balloon1);
			level.Add(balloon2);
			level.Add(balloon3);
			level.Add(balloon4);

			CTestVisitor visitor;
			level.Accept(&visitor);
			Assert::AreEqual(4, visitor.mNumBalloons);

			// add another item and make sure it is not counted as a balloon
			auto house1 = std::make_shared<CItemTile>(&level, &game, 11);
			level.Add(house1);

			CTestVisitor visitor2;
			level.Accept(&visitor2);
			Assert::AreEqual(4, visitor2.mNumBalloons);

		}

	};
}