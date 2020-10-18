#include "pch.h"
#include "CppUnitTest.h"
#include "ProjectileDart.h"
#include "Game.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

/// dart filename
const std::wstring dartImageName = L"images/dart.png";

/// dart id number
const int dartID = 55;

/// The basic level for testing
const std::wstring baseLevel = L"levels/level0.xml";

/// pi
const double pi = 3.14159265358979323846;
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
			CDartMock dart(&level, &game, dartID);
		}

		TEST_METHOD(TestCProjectileDartGetterSetter)
		{
			CGame game;
			CLevel level(&game, baseLevel);
			CDartMock dart(&level, &game, dartID);

			Assert::AreEqual(0, dart.GetAngle(), 0);
			dart.SetAngle();
			Assert::AreEqual(pi / 4, dart.GetAngle(), 0);
			dart.SetAngle();
			dart.SetAngle();
			dart.SetAngle();
			Assert::AreEqual(pi, dart.GetAngle(), 0);
			dart.SetAngle();
			dart.SetAngle();
			dart.SetAngle();
			dart.SetAngle();
			Assert::AreEqual(0, dart.GetAngle(), 0);
			dart.SetAngle();
			Assert::AreEqual(pi / 4, dart.GetAngle(), 0);

		}
	};
}