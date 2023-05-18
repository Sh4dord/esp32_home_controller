#pragma once
#ifndef BASE_H
#define BASE_H


#include <Arduino_GFX_Library.h>

/* HAL */
#define USE_SDCARD     0
#define USE_TOUCH      0

/*
TFT pins should be set in path .pio/libdeps/esp32dev/TFT_eSPI/User_Setups/Setup1_ILI9341.h
*/
/* TFT */
static Arduino_DataBus *bus = new Arduino_ESP32SPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
static Arduino_GFX *gfx = new Arduino_ST7789(bus, -1 /* RST */, 3 /* rotation */, true /* IPS */);

#endif 