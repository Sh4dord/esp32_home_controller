#include "display.h"




static void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    Serial.println("[DISPLAY] : Flush");
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);

    lv_disp_flush_ready(disp);
    lv_disp_flush_ready(disp);
    Serial.println("[DISPLAY] : Flush End");
}

void Display::init()
{
    Serial.println("[DISPLAY] : Init");

    // Init touch device

    // Init Display
    // gfx->begin();
    gfx->begin(80000000);
    Serial.println("[DISPLAY] : GFX begin");

    // delay(1000);
    lv_init();
    Serial.println("[DISPLAY] : LVGL init");
    delay(20);
    screenWidth = gfx->width();
    screenHeight = gfx->height();

    disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * screenHeight / 2, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);

    if (!disp_draw_buf)
    {
        Serial.println("LVGL disp_draw_buf allocate failed!");
    }
    else
    {
        lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * screenHeight / 2);

        /* Initialize the display */
        lv_disp_drv_init(&disp_drv);
        /* Change the following line to your display resolution */
        disp_drv.hor_res = screenWidth;
        disp_drv.ver_res = screenHeight;
        disp_drv.flush_cb = disp_flush;
        disp_drv.draw_buf = &draw_buf;
        lv_disp_drv_register(&disp_drv);
    }
    Serial.println("[DISPLAY] : Init End");
}

void Display::routine()
{
    lv_task_handler();
}
