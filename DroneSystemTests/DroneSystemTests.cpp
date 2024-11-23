#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "DroneSystem.h"



namespace DroneSystemTests
{
	TEST_CLASS(DroneSystemTests)
	{
	public:
		// could not automate testing DSS 104 since null pointers throw exceptions
		TEST_METHOD(DSS_103)
		{
			// verify drone system is created in a safe empty state
			DroneSystem d(3);
			Assert::AreEqual(d.drones[0]->getBatteryLevel(), 100.0f);
			Assert::AreEqual(d.drones[0]->getDamage(), "Undamaged");
			Assert::AreEqual(d.drones[0]->getStatus(), "Undeployed");

			Assert::AreEqual(d.drones[1]->getBatteryLevel(), 100.0f);
			Assert::AreEqual(d.drones[1]->getDamage(), "Undamaged");
			Assert::AreEqual(d.drones[1]->getStatus(), "Undeployed");

			Assert::AreEqual(d.drones[2]->getBatteryLevel(), 100.0f);
			Assert::AreEqual(d.drones[2]->getDamage(), "Undamaged");
			Assert::AreEqual(d.drones[2]->getStatus(), "Undeployed");
		}
		TEST_METHOD(DSS_101)
		{
			// verify drone system reads data from a file and stores correctly
			DroneSystem d;
			d.drones[0]->setBatteryLevel(20.0f);
			d.drones[0]->setDamage(BROKEN);
			d.drones[0]->setStatus(REPAIRING);
			d.drones[1]->setBatteryLevel(27.0f);
			d.writeDataToFile("dronesystemtestfile.txt");
			DroneSystem readData;
			readData.readDataFromFile("dronesystemtestfile.txt");

			Assert::AreEqual(readData.drones[0]->getBatteryLevel(), 20.0f);
			Assert::AreEqual(readData.drones[0]->getDamage(), "Broken");
			Assert::AreEqual(readData.drones[0]->getStatus(), "Repairing");
			Assert::AreEqual(readData.drones[1]->getBatteryLevel(), 27.0f);
			
		}
	};
}
