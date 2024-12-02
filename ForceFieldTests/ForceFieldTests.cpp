#include "pch.h"
#include "CppUnitTest.h"
#include "ForceField.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ForceFieldTests
{
	TEST_CLASS(ForceFieldTests)
	{
	public:
		
        TEST_METHOD(InitializationTest)
        {
            // Test default initialization
            ForceField ff;
            Assert::AreEqual(ff.isForceFieldActive(), true);
            Assert::AreEqual(ff.getChargeLevel(), 100.0f);
        }

        TEST_METHOD(DetectBreachTest)
        {
            // Test detecting a breach
            ForceField ff;
            ff.setForceFieldStatus(false);
            ff.detectBreach();
            Assert::AreEqual(ff.isForceFieldActive(), false);
        }

        TEST_METHOD(ChargeForceFieldTest)
        {
            // Test charging the force field
            ForceField ff;
            ff.setForceFieldChargingStatus(true);
            ff.setForceFieldCharge(50.0f);
            ff.chargeForceField();
            Assert::AreEqual(ff.getChargeLevel(), 50.005f); // Charging increases by 0.005
        }

        TEST_METHOD(ForceFieldAttackTest)
        {
            // Test force field attack
            ForceField ff;
            ff.forceFieldAttack(20.0f);
            Assert::AreEqual(ff.getChargeLevel(), 80.0f); // Charge decreases by the damage value
        }

        TEST_METHOD(IsForceFieldActiveTest)
        {
            // Test if force field status is correctly reported
            ForceField ff;
            Assert::IsTrue(ff.isForceFieldActive()); // Initially active
            ff.setForceFieldStatus(false);
            Assert::IsFalse(ff.isForceFieldActive()); // Now inactive
        }

        TEST_METHOD(TimeToFullChargeTest)
        {
            // Test time to full charge calculation
            ForceField ff;
            ff.setForceFieldCharge(50.0f);
            ff.setForceFieldChargingStatus(true);
            float expectedTime = (100.0f - 50.0f) / 0.005f / 60.0f; // Calculate expected time
            Assert::AreEqual(ff.timeToFullCharge(), expectedTime);
        }

        TEST_METHOD(FileWriteReadTest)
        {
            // Test writing to and reading from a file
            ForceField ff;
            ff.setForceFieldStatus(false);
            ff.setForceFieldCharge(75.0f);
            ff.setForceFieldChargingStatus(true);

            const std::string filename = "fftestfile.txt";
            ff.FFwriteToFile(filename);

            ForceField ff2;
            ff2.FFreadFromFile(filename);

            Assert::AreEqual(ff2.isForceFieldActive(), false);
            Assert::AreEqual(ff2.getChargeLevel(), 75.0f);
            Assert::IsTrue(ff2.timeToFullCharge() > 0.0f);
        }
	};
}
