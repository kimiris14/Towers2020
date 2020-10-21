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


	TEST_CLASS(CDisplayLevelTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(DisplayTitleTest)
		{
			CGame game;
			CLevel level(&game, baseLevel);

			// test that the title is not displayed after 2 seconds or while the level is active
			if (level.GetElapsedTime() > 2 || level.IsActive() == true)
			{
				Assert::IsTrue(level.IsTitleDisplayed() == false);

			}

			

		}

	};
}