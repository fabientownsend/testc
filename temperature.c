#include <stdio.h>
#include "lib/unity_fixture.h"

#include "myheader.h"

TEST_GROUP(Temperature);
TEST_SETUP(Temperature) { }
TEST_TEAR_DOWN(Temperature) { }

float ConvertCelciusToFahrenheit(float celcius);
float ConvertCelciusToKelvin(float celcius);

TEST(Temperature, CelciusToFahreneit)
{
  float celcius = 1;
  float kelvin = 33;

  TEST_ASSERT_EQUAL_INT(ConvertCelciusToFahrenheit(celcius), kelvin);
}

TEST(Temperature, CelciusToKelvin)
{
  float celcius = 1;
  float kelvin = 274;

  TEST_ASSERT_EQUAL_INT(ConvertCelciusToKelvin(celcius), kelvin);
}

static void runAllTests() {
  RUN_TEST_CASE(Temperature, CelciusToKelvin);
  RUN_TEST_CASE(Temperature, CelciusToFahreneit);

}

int main(int argc, const char* argv[])
{
  UnityMain(argc, argv, runAllTests);
}

float ConvertCelciusToFahrenheit(float celcius)
{
  return celcius * 1.8 + 32;
}

float ConvertCelciusToKelvin(float celcius)
{
  return celcius += 273.15;
}
