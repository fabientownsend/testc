#include <stdint.h>
#include "myheader.h"

enum {
  ALL_LEDS_ON = ~0,
  ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t *ledAddress;

void LedDriver_Create(uint16_t *address)
{
  ledAddress = address;
  *ledAddress = ALL_LEDS_OFF;
}

static uint16_t convertLedNumberToBit(ledNumber) {
  return 1 << (ledNumber - 1);
}

void LedDriver_TurnOn(int ledNumber)
{
  *ledAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
  *ledAddress &= ~(convertLedNumberToBit(ledNumber));
}

void LedDriver_TurnAllOn()
{
  *ledAddress = ALL_LEDS_ON;
}

float ConvertCelciusToFahrenheit(float celcius)
{
  return celcius * 1.8 + 32;
}

float ConvertCelciusToKelvin(float celcius)
{
  return celcius += 273.15;
}
