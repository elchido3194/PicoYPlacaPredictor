#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PicoYPlaca/TimeValidator.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	TEST_CLASS(TimeValidatorTest)
	{
	public:

		TEST_METHOD(TestisTimeCorrect)
		{
			//Arrange
			std::string time = "09:38";
			TimeValidator Tv;
			//Act
			bool res = Tv.isTimeCorrect(time);
			//Assert
			Assert::IsTrue(res);
		}

		TEST_METHOD(TestgetHour) {
			//Arrange
			std::string time = "09:15";
			int expected = 9;
			TimeValidator Tv;
			//Act
			int result = Tv.getHour(time);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestgetMin) {
			//Arrange
			std::string time = "09:15";
			int expected = 15;
			TimeValidator Tv;
			//Act
			int result = Tv.getMin(time);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestrestrictedTime) {
			//Arrange
			std::string time = "09:15";
			TimeValidator Tv;
			//Act
			bool result = Tv.restrictedTime(time);
			//Assert
			Assert::IsTrue(result);
		}

	};
}