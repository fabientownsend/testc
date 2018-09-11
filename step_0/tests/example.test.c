#include <stdio.h>
#include "../lib/unity_fixture.h"

TEST_GROUP(Example_Group);
TEST_SETUP(Example_Group) { }
TEST_TEAR_DOWN(Example_Group) { }

TEST(Example_Group, ExampleTest)
{
  TEST_ASSERT_EQUAL_INT(0, 1);
}

static void runAllTests() {
  RUN_TEST_CASE(Example_Group, ExampleTest);
}

int main(int argc, const char* argv[])
{
  UnityMain(argc, argv, runAllTests);
}
