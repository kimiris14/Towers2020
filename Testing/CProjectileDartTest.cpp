#include "pch.h"
#include "CppUnitTest.h"
#include "ProjectileDart.h"
#include "Game.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

/// red balloon filename
const std::wstring dartImageName = L"images/dart.png";

/// red balloon id number
const int dartID = 55;

/// The basic level for testing
const std::wstring baseLevel = L"levels/level0.xml";

namespace Testing
{
	/** Mock class for testing CItem */
	class CDartMock : public CProjectileDart
	{
	public:
		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param game The Game this item is a member of
		* \param imageID The image id for this item
		*/
		CDartMock(CLevel* level, CGame* game, int imageID)
			: CProjectileDart(level, game, imageID)
		{

			game->AddImage(dartID, dartImageName);
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};


	TEST_CLASS(CProjectileDartTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCProjectileDartConstruct)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CProjectileDart dart(&level, &game, dartID);
		}
	};
}