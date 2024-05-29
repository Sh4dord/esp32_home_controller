
/*******************************************************************************
 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 ******************************************************************************/
//

/* uncomment for GT911 */
#define TOUCH_GT911
#define TOUCH_GT911_SCL 32
#define TOUCH_GT911_SDA 33
#define TOUCH_GT911_INT -1
#define TOUCH_GT911_RST 25
#define TOUCH_GT911_ROTATION ROTATION_RIGHT // ROTATION_NORMAL
#define TOUCH_MAP_X1 320
#define TOUCH_MAP_X2 0
#define TOUCH_MAP_Y1 240
#define TOUCH_MAP_Y2 0

int touch_last_x = 0, touch_last_y = 0;
#include <Arduino_GFX_Library.h>
#include <Wire.h>
#include <Touch_GT911.h>

Touch_GT911 ts = Touch_GT911(TOUCH_GT911_SDA, TOUCH_GT911_SCL, TOUCH_GT911_INT, TOUCH_GT911_RST, max(TOUCH_MAP_X1, TOUCH_MAP_X2), max(TOUCH_MAP_Y1, TOUCH_MAP_Y2));
Arduino_DataBus *bus = new Arduino_ESP32SPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, -1 /* RST */, 3 /* rotation */, true /* IPS */);


void touch_init()
{

  Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
  ts.begin();
  ts.setRotation(TOUCH_GT911_ROTATION);
}

bool touch_has_signal()
{

  return true;
}

bool touch_touched()
{

  ts.read();
  if (ts.isTouched)
  {

    touch_last_x = map(ts.points[0].x, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, gfx->width() - 1);
    touch_last_y = map(ts.points[0].y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, gfx->height() - 1);

    return true;
  }
  else
  {
    return false;
  }
}

bool touch_released()
{
  return true;
}
