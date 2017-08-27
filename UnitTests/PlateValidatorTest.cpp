#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PicoYPlaca/PlateValidator.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{		
	TEST_CLASS(PlateValidatorTest)
	{
	public:
		
		TEST_METHOD(TestplateIsCorrect)
		{
			//Arrange
			std::string plate1 = "PBX-214"; 
			std::string plate2 = "PBX-2124"; 
			//std::string plate3 = "AAA-AAAA"; 
			//Act
			bool res1 = plateIsCorrect(plate1);
			bool res2 = plateIsCorrect(plate2);

			//Assert
			Assert::IsTrue(res1);
			Assert::IsTrue(res2);
		}

	};
}