#include "pch.h"
#include "CppUnitTest.h"
#include "MonsterContainmentUnit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MonsterContainmentUnitTests
{
	TEST_CLASS(MonsterContainmentUnitTests)
	{
	public:
		
        TEST_METHOD(InitializationTest)
        {
            // Test default initialization
            MonsterContainmentUnit mcu;
            Assert::AreEqual(mcu.getHungerLevel(), 80.0f);
            Assert::AreEqual(mcu.getAngerLevel(), 10.0f);
            Assert::IsTrue(mcu.getContainmentStatus());
        }

        TEST_METHOD(FeedMonsterTest)
        {
            // Test feeding the monster
            MonsterContainmentUnit mcu;
            mcu.feedMonster();
            Assert::AreEqual(mcu.getHungerLevel(), 100.0f); // Hunger level maxes at 100
            Assert::AreEqual(mcu.getAngerLevel(), 5.0f);    // Anger level decreases by 5
        }

        TEST_METHOD(SedateMonsterTest)
        {
            // Test sedating the monster
            MonsterContainmentUnit mcu;
            mcu.sedateMonster();
            Assert::AreEqual(mcu.getAngerLevel(), 0.0f); // Anger level decreases but cannot go below 0
        }

        TEST_METHOD(ReleaseMonsterTest)
        {
            // Test releasing the monster
            MonsterContainmentUnit mcu;
            mcu.releaseMonster();
            Assert::IsFalse(mcu.getContainmentStatus()); // Containment status should be false
        }

        TEST_METHOD(CheckHungerLevelTest)
        {
            // Test if hunger level affects anger
            MonsterContainmentUnit mcu;
            mcu.setHungerLevel(20.0f); // Set hunger level below 25
            mcu.checkHungerLevel();
            Assert::AreEqual(mcu.getAngerLevel(), 60.0f); // Anger increases by 50
        }

        TEST_METHOD(FileWriteReadTest)
        {
            // Test writing to and reading from a file
            MonsterContainmentUnit mcu;
            mcu.setHungerLevel(60.0f);
            mcu.setAngerLevel(40.0f);
            mcu.setContainmentStatus(false);

            const std::string filename = "mcutestfile.txt";
            mcu.MCUwriteToFile(filename);

            MonsterContainmentUnit mcu2;
            mcu2.MCUreadFromFile(filename);

            Assert::AreEqual(mcu2.getHungerLevel(), 60.0f);
            Assert::AreEqual(mcu2.getAngerLevel(), 40.0f);
            Assert::IsFalse(mcu2.getContainmentStatus());
        }
	};
}
