#include <stdio.h>
#include "myheader.h"
#include "unity_fixture.h"

TEST_GROUP(LedDriver);
TEST_SETUP(LedDriver) { }
TEST_TEAR_DOWN(LedDriver) { }

TEST(LedDriver, LedsOffAfterCreate)
{
  uint16_t virtualLeds = 0xffff;

  LedDriver_Create(&virtualLeds);

  TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);

  LedDriver_TurnOn(1);

  TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);

  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);

  TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);

  LedDriver_TurnOn(8);
  LedDriver_TurnOn(9);

  TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);
}

TEST(LedDriver, TurnAllLedsOn)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);

  LedDriver_TurnAllOn();

  TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  LedDriver_TurnAllOn();

  LedDriver_TurnOff(8);

  TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReable)
{
  uint16_t virtualLeds = 0xffff;

  LedDriver_TurnOn(8);

  // TEST_ASSERT_EQUAL_HEX16(80, virtualLeds);
}


static void runAllTests() {
  RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
  RUN_TEST_CASE(LedDriver, TurnOnLedOne);
  RUN_TEST_CASE(LedDriver, TurnOffLedOne);
  RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
  RUN_TEST_CASE(LedDriver, TurnAllLedsOn);
  RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
  RUN_TEST_CASE(LedDriver, LedMemoryIsNotReable);
}

int main(int argc, const char* argv[])
{
  UnityMain(argc, argv, runAllTests);
}
