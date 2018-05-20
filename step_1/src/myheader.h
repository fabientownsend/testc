#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn();

float ConvertCelciusToFahrenheit(float celcius);
float ConvertCelciusToKelvin(float celcius);

#endif
