#include <os.h>
#include <libndls.h>

#include "touchpad.h"

bool had_contact = false;
uint16_t _x = 0; uint16_t _y = 0;
uint16_t x = 0; uint16_t y = 0;
uint16_t vx = 0; uint16_t vy = 0;
touchpad_report_t touchpad;

void update_tpad()
{
    touchpad_scan(&touchpad);

    if(had_contact && touchpad.contact)
    {
        vx = touchpad.x - x; // current - old = change
        vy = touchpad.y - y;
    }

    had_contact = touchpad.contact;
    x = touchpad.x;
    y = touchpad.y;
}

tpad get_tpad() {
    tpad t;

    // tpad motion

    t.x = x; t.y = y;
    t.vx = vx; t.vy = vy;

    t.contact = touchpad.contact;

    return t;
        
}
