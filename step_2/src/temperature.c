#include <stdint.h>
#include "temperature.h"

float ConvertCelciusToFahrenheit(float celcius)
{
  return celcius * 1.8 + 32;
}

float ConvertCelciusToKelvin(float celcius)
{
  return celcius += 273.15;
}
