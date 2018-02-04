#include <stdio.h>
#include "myheader.h"
#include "unity_fixture.h"

TEST_GROUP(myheader);
TEST_SETUP(myheader) { }
TEST_TEAR_DOWN(myheader) { }

TEST(myheader, willReturnTwo)
{
  TEST_ASSERT(add(1, 1) == 2);
}

TEST(myheader, willReturnFour)
{
  TEST_ASSERT(add(2, 2) == 4);
}

TEST(myheader, willFail)
{
  TEST_ASSERT(add(1, 3) == 4);
}

TEST(myheader, newTest)
{
  int result = aNewFunction();
  TEST_ASSERT(result == 6);
}

TEST_GROUP_RUNNER(myheaer) {
  RUN_TEST_CASE(myheader, willReturnTwo);
  RUN_TEST_CASE(myheader, willReturnFour);
  RUN_TEST_CASE(myheader, willFail);
}

void LedDriver_Create(uint16_t *address)
{
  *address = 0;
}

static void runAllTests() {
  RUN_TEST_CASE(myheader, willReturnTwo);
  RUN_TEST_CASE(myheader, willReturnFour);
  RUN_TEST_CASE(myheader, willFail);
  RUN_TEST_CASE(myheader, newTest);
}

int main(int argc, const char* argv[])
{
  uint16_t virtualLeds = 0xffff;
  printf("before virtual led: %d\n", virtualLeds);
  LedDriver_Create(&virtualLeds);
  printf("after virtual led: %d\n", virtualLeds);
  UnityMain(argc, argv, runAllTests);
}
