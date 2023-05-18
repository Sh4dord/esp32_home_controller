
/*******************************************************************************
 * LVGL Widgets
 * This is a widgets demo for LVGL - Light and Versatile Graphics Library
 * import from: https://github.com/lvgl/lv_demos.git
 *
 * Dependent libraries:
 * LVGL: https://github.com/lvgl/lvgl.git

 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 *
 * LVGL Configuration file:
 * Copy your_arduino_path/libraries/lvgl/lv_conf_template.h
 * to your_arduino_path/libraries/lv_conf.h
 * Then find and set:
 * #define LV_COLOR_DEPTH     16
 * #define LV_TICK_CUSTOM     1
 *
 * For SPI display set color swap can be faster, parallel screen don't set!
 * #define LV_COLOR_16_SWAP   1
 *
 * Optional: Show CPU usage and FPS count
 * #define LV_USE_PERF_MONITOR 1
 ******************************************************************************/
// #include "lv_demo_widgets.h"
#include <lvgl.h>
#include "base.h"
#include "display.h"
#include <lv_demo_widgets.h>
#include "touch.h"

/* Change to your screen resolution */

Display screen;
Touch touch;

void setup()
{ 
  Serial.begin(115200);
  Serial.println("[SETUP] : Init");
  screen.init();
  touch.init();
  lv_demo_widgets();
  Serial.println("[SETUP] : End");
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(50);
}
