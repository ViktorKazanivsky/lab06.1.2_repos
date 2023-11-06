#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1.2/Lab_06_1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int min = 15;
			int max = 85;

			int randomNum = RandomNumberGeneration(min, max);

			Assert::IsTrue(randomNum >= min);
			Assert::IsTrue(randomNum <= max);
		}

		TEST_METHOD(TestMethod2)
		{
			const int arraySize = 21;
			int Array[arraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

			int count = CountCorrectElements(Array);

			int expectedCount = 11;

			Assert::AreEqual(count, expectedCount);
		}
	};
}
