#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PicoYPlaca/DateValidator.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	TEST_CLASS(DateValidatorTest)
	{
	public:

		TEST_METHOD(TestdateCorrect)
		{
			//Arrange
			std::string date = "31/01/2000";
			DateValidator Dv;
			//Act
			bool result = Dv.dateCorrect(date);
			//Assert
			Assert::IsTrue(result);
			
		}
		TEST_METHOD(TestgetDayOfWeek_date)
		{
			//Arrange
			std::string date = "31/01/2000"; //31/01/2000 was a Monday
			//mktime returns an int depending on the weekday
			//Sunday = 0, Monday = 1, Tuesday 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6
			DateValidator Dv;
			//Act
			int result = Dv.getDayOfWeek_date(date);
			//Assert
			Assert::AreEqual(1, result);//1 for Monday
		}
		TEST_METHOD(TestgetDayOfWeek_plate)
		{
			//Arrange 
			std::string plate = "PBL-8310";
			DateValidator Dv;
			//Act
			//This returns the restricted weekday depending on the plate
			// Monday = 0, Tuesday 1, Wednesday = 2, Thursday = 3, Friday = 4
			int result = Dv.getDayOfWeek_plate(plate);
			//Assert
			Assert::AreEqual(4, result);//The plate ends in 0, so Friday is the restricted day
		}
		TEST_METHOD(TestgetDay)
		{
			//Arrange
			std::string date = "31/01/2000";
			int expected = 31;
			DateValidator Dv;
			//Act
			int result = Dv.getDay(date);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestgetMonth)
		{
			//Arrange
			std::string date = "31/01/2000";
			int expected = 01;
			DateValidator Dv;
			//Act
			int result = Dv.getMonth(date);
			//Assert
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestgetYear)
		{
			//Arrange
			std::string date = "31/01/2000";
			int expected = 2000;
			DateValidator Dv;
			//Act
			int result = Dv.getYear(date);
			//Assert
			Assert::AreEqual(expected, result);
		}

	};
}