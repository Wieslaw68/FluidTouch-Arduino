#ifndef UI_TAB_CONTROL_JOYSTICK_H
#define UI_TAB_CONTROL_JOYSTICK_H

#include <lvgl.h>

class UITabControlJoystick {
public:
    static void create(lv_obj_t *tab);
    static void loop();
};

#endif // UI_TAB_CONTROL_JOYSTICK_H
