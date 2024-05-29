/*#pragma once
#ifndef BASE_H
#define BASE_H


#include <Arduino_GFX_Library.h>


#define USE_SDCARD     0
#define USE_TOUCH      0


static Arduino_DataBus *bus = new Arduino_ESP32SPI(2, 15 , 14, 13 , GFX_NOT_DEFINED);
static Arduino_GFX *gfx = new Arduino_ST7789(bus, -1, 3 , true);

#endif */