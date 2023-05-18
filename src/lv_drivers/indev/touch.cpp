#include "touch.h"
#include "lvgl.h"
#include "base.h"



static void touch_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{

    if (touch_has_signal())
    {
        if (touch_touched())
        {
            data->state = LV_INDEV_STATE_PR;

            /*Set the coordinates*/
            data->point.x = touch_last_x;
            data->point.y = touch_last_y;
        }
        else if (touch_released())
        {
            data->state = LV_INDEV_STATE_REL;
        }
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

 void touch_init()
{
    
	Wire.begin(TOUCH_GT911_SDA, TOUCH_GT911_SCL);
    Serial.println("[TOUCH] : Wire begin");
	ts.begin();
    Serial.println("[TOUCH] : ts begin");
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

void Touch::init()
{
    Serial.println("[TOUCH] : Init");
    touch_init();
    /*Initialize the input device driver*/
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Descriptor of a input device driver*/
    indev_drv.type = LV_INDEV_TYPE_POINTER; /*Touchpad is a pointer-like device*/
    indev_drv.read_cb = touch_read;
    lv_indev_drv_register(&indev_drv);
    Serial.println("[TOUCH] : Init End");
}
