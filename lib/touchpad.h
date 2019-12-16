#ifndef TOUCHPAD_H
#define TOUCHPAD_H

#include <os.h>
#include <libndls.h>

extern bool had_contact;
extern uint16_t _x; extern uint16_t _y;
extern uint16_t x; extern uint16_t y;
extern uint16_t vx; extern uint16_t vy;
extern touchpad_report_t touchpad;

struct tpad
{
    uint16_t x;
    uint8_t y;
    uint16_t vx;
    uint8_t vy;
    bool contact;
};

void update_tpad();

tpad get_tpad();

#endif