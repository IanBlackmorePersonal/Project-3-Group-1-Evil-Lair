#include "pch.h"
#include "CppUnitTest.h"
#include "UndergroundGarden.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UDGTesting
{
	TEST_CLASS(UDGTesting)
	{
	public:
		
		TEST_METHOD(UDG_103)
		{
			//verify udg is created in a safe empty state
			UndergroundGarden u;
			Assert::AreEqual(u.getHumidity(), 80.0f);
			Assert::AreEqual(u.getSoilPH(), 7.0f);
			Assert::AreEqual(u.getSprinklerStatus(), false);
			
		}
		TEST_METHOD(UDG_104)
		{
			// verify UDG is destroyed properly
			// has no dynamic memory, always destroys properly
			{
				UndergroundGarden u;
			}
			
		}
		TEST_METHOD(UDG_101)
		{
			// verify UDG can read and store data from a file
			{
				UndergroundGarden u;
				u.setHumidity(27.0f);
				u.setSoilPH(2.0f);
				u.setSprinklerStatus(true);
				u.writeDataToFile("testUDG.txt");
			}
			UndergroundGarden readData;
			readData.readDataFromFile("testUDG.txt");
			Assert::AreEqual(readData.getHumidity(), 27.0f);
			Assert::AreEqual(readData.getSoilPH(), 2.0f);
			Assert::AreEqual(readData.getSprinklerStatus(), true);
		}
	};
}
