#include "pch.h"
#include "CppUnitTest.h"

#include "XmlNode.h"
#include "Game.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

namespace Testing
{


	TEST_CLASS(CGameTest)
	{
	public:
        /**
        * Create a path to a place to put temporary files
        */
        wstring TempPath()
        {
            // Create a path to temporary files
            wchar_t path_nts[MAX_PATH];
            GetTempPath(MAX_PATH, path_nts);

            // Convert null terminated string to wstring
            return wstring(path_nts);
        }

        /**
        * Read a file into a wstring and return it.
        * \param filename Name of the file to read
        * \return File contents
        */
        wstring ReadFile(const wstring& filename)
        {
            ifstream t(filename);
            wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

            return str;
        }

        /**
        * Test to ensure an aquarium .aqua file is empty
        */
        void TestEmpty(wstring filename)
        {
            Logger::WriteMessage(filename.c_str());

            wstring xml = ReadFile(filename);
            Logger::WriteMessage(xml.c_str());

            Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
            Assert::IsTrue(regex_search(xml, wregex(L"<xml/>")));
        }

        TEST_METHOD(TestCGameSave)
        {
            // Create a path to temporary files
            wstring path = TempPath();

            // Create an level
            CGame game;

            //
            // First test, saving an empty level
            //
            wstring file1 = path + L"test1.xml";
            game.Save(file1);

            TestEmpty(file1);
        }

        TEST_METHOD(TestCGameClear)
        {
            // Create an level
            CGame game;
            game.Clear();
        }
        TEST_METHOD(TestCGameLoad)
        {
            // Create a path to temporary files
            wstring path = TempPath();

            // Create an level
            CGame game, game2;

            //
            // First test, saving an empty level
            //
            wstring file1 = path + L"test1.xml";
            game.Save(file1);
            TestEmpty(file1);

            game2.Load(file1);
            game2.Save(file1);
            TestEmpty(file1);
        }
	};
}