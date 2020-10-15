#include "pch.h"
#include "CppUnitTest.h"
#include "ProjectileBomb.h"
#include "Game.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

/// bomb id number
const int bombID = 53;

/// The basic level for testing
const std::wstring baseLevel = L"levels/level0.xml";

namespace Testing
{
	/** Mock class for testing CItem */
	class CBombMock : public CProjectileBomb
	{
	public:
		/**
		* Constructor
		* \param level, the level that this game item is a part of
		* \param game The Game this item is a member of
		* \param imageID The image id for this item
		*/
		CBombMock(CLevel* level, CGame* game, int imageID)
			: CProjectileBomb(level, game, imageID)
		{
		}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor* visitor) override { }
	};
	TEST_CLASS(CProjectileBombTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestProjectileBombConstruct)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CProjectileBomb bomb(&level, &game, bombID);
		}

	};
}