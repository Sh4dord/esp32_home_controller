#include<lvgl.h>

static void fade_anim_cb(void *obj, int32_t v)
{
  lv_obj_set_style_opa((lv_obj_t *)obj, v, 0);
}


lv_obj_t* init_splash_screen() {
     lv_obj_t* splash_screen = lv_obj_create(NULL);


    static lv_style_t screenStyle;
    
    lv_style_init(&screenStyle);
    lv_style_set_bg_color(&screenStyle, lv_color_black());
    lv_obj_add_style(splash_screen, &screenStyle, 0);

    /*Create a container with COLUMN flex direction*/
    lv_obj_t * column = lv_obj_create(splash_screen);
    lv_obj_set_flex_flow(column, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(column, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);



    LV_IMAGE_DECLARE(LOGO_TT);
    lv_obj_t *img1 = lv_image_create(column);
    lv_obj_set_style_opa(img1, 0, 0);
    lv_image_set_src(img1, &LOGO_TT);
    //lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);

    LV_IMAGE_DECLARE(LOGO_AUDI);
    lv_obj_t *img2 = lv_image_create(column);
    lv_obj_set_style_opa(img2, 0, 0);
    lv_image_set_src(img2, &LOGO_AUDI);

    lv_anim_t animation_tt;
    lv_anim_init(&animation_tt);
    lv_anim_set_var(&animation_tt, img1);
    lv_anim_set_values(&animation_tt, 0, LV_OPA_COVER);
    lv_anim_set_exec_cb(&animation_tt, fade_anim_cb);
    lv_anim_set_duration(&animation_tt, 1000);
    lv_anim_set_delay(&animation_tt, 0);
    lv_anim_start(&animation_tt);

    lv_anim_t animation_audi;
    lv_anim_init(&animation_audi);
    lv_anim_set_var(&animation_audi, img2);
    lv_anim_set_values(&animation_audi, 0, LV_OPA_COVER);
    lv_anim_set_exec_cb(&animation_audi, fade_anim_cb);
    lv_anim_set_duration(&animation_audi, 800);
    lv_anim_set_delay(&animation_audi, 200);
    lv_anim_start(&animation_audi);

    return splash_screen;
}