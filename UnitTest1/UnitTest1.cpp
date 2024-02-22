#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.2it/LAB_7.2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreateFunction)
		{
			const int n = 3;
			const int Low = 2;
			const int High = 10;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			Create(a, n, Low, High);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
				}
			}

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSearchMinMaxFunction)
		{
			const int n = 3; 
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 3; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int minAbove, maxBelow;
			bool result = SearchMinMax(a, n, minAbove, maxBelow);

			Assert::AreEqual(minAbove, 3); 
			Assert::AreEqual(maxBelow, 3);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSwapMinMaxFunction)
		{
			const int n = 3;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			a[0][0] = 6; a[0][1] = 2; a[0][2] = 3; 
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 1; 
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int minAbove, maxBelow;
			SearchMinMax(a, n, minAbove, maxBelow);
			SwapMinMax(a, n);

			
			Assert::AreEqual(a[0][1], 2);
			
			Assert::AreEqual(a[1][2], 1);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
