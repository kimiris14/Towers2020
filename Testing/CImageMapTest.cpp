#include "pch.h"
#include "CppUnitTest.h"
#include "ImageMap.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

namespace Testing
{

	TEST_CLASS(CImageMapTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestMapInitialize)
		{
			CImageMap map;
		}
		
		TEST_METHOD(TestGetImageEmpty)
		{
			CImageMap map;

			wstring testString = L"no_image_here.png";

			shared_ptr<Bitmap> bitmap = map.GetImage(testString);

			Assert::IsNull(bitmap.get());
		}


		TEST_METHOD(TestGetImage)
		{
			CImageMap map;

			// test image
			wstring testID = L"i001";
			wstring testImage = L"images/red-balloon.png";

			// should not be in the map
			shared_ptr<Bitmap> bitmap1 = map.GetImage(testID);
			Assert::IsNull(bitmap1.get());

			// add image to the map (also tests proper image loading)
			map.AddImage(testID, testImage);

			// should be in the map now
			shared_ptr<Bitmap> bitmap2 = map.GetImage(testID);
			Assert::IsNotNull(bitmap2.get());

		}

		TEST_METHOD(TestNoDupes)
		{
			CImageMap map;

			// test image
			wstring testID = L"i001";
			wstring testImage = L"images/red-balloon.png";

			// add image to the map
			map.AddImage(testID, testImage);

			// add the same image to the map
			map.AddImage(testID, testImage);

			// there should only be one image in the map
			Assert::AreEqual(map.GetSize(), (size_t) 1);

		}


		TEST_METHOD(TestImageLoading)
		{
			CImageMap map;

			// test image
			wstring testID = L"i001";
			wstring testImage = L"images/red-balloon.png";

			// add image to the map
			map.AddImage(testID, testImage);

			shared_ptr<Bitmap> bitmap = map.GetImage(testID);

			// make sure that the image was loaded ok
			Assert::IsTrue(bitmap.get()->GetLastStatus() == Ok);

		}

	};
}