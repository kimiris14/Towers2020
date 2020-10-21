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
	/// red balloon filename
	const std::wstring redBalloonImageName = L"images/red-balloon.png";

	/// red balloon id number
	const int redBalloonID = 44;

	/// The basic level for testing
	const std::wstring baseLevel = L"levels/level0.xml";

	/** Mock class for testing CTile */
	class CItemBalloonMock : public CItemBalloon
	{
	public:

		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param game, the game this item is a part of
		* \param imageID The image id for this item
		*/
		CItemBalloonMock(CLevel* level, CGame* game)
			: CItemBalloon(level, game)
		{
			SetImageID(redBalloonID);  
			game->AddImage(redBalloonID, redBalloonImageName);
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }

	};

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

		TEST_METHOD(ItemVisitorTests)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			// add balloons to the game
			CItemBalloonMock balloon(&level, &game);
			CItemBalloonMock balloon2(&level, &game);
			CItemBalloonMock balloon3(&level, &game);
			CItemBalloonMock balloon4(&level, &game);

			CTestVisitor visitor;
			level.Accept(&visitor);
			Assert::AreEqual(4, visitor.mNumBalloons);

		}

	};
}