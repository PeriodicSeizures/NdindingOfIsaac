#ifndef ETERNAL_HEART_PNG_H
#define ETERNAL_HEART_PNG_H

#include "../../../lib/gl2d.h"

static uint16_t eternal_heart_data[] = {
  0x1, 0x1, 0x1, 0x800, 0x800, 0x1, 0x1, 0x1, 0x800, 0x800, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x800, 0x18e3, 0x18e3, 0x0, 0x1, 0x0, 0x18e3, 0x18e3, 0x800, 0x1, 0x1, 
  0x1, 0x800, 0x18e3, 0xffff, 0xffff, 0x18e3, 0x800, 0x18e3, 0x1, 0x1, 0x18e3, 0x800, 0x1, 
  0x800, 0x18e3, 0xffff, 0xffff, 0xffff, 0xffff, 0x18e3, 0x1, 0x1, 0x1, 0x1, 0x18e3, 0x800, 
  0x800, 0x18e3, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x1, 0x1, 0x1, 0x1, 0x18e3, 0x800, 
  0x800, 0x18e3, 0xc618, 0xffff, 0xffff, 0xffff, 0x1, 0x1, 0x1, 0x1, 0x1, 0x18e3, 0x0, 
  0x1, 0x800, 0x18e3, 0xc618, 0xffff, 0xffff, 0xffff, 0x1, 0x1, 0x1, 0x18e3, 0x800, 0x1, 
  0x1, 0x1, 0x800, 0x18e3, 0xc618, 0xffff, 0x1, 0x1, 0x1, 0x18e3, 0x0, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x800, 0x18e3, 0xc618, 0xffff, 0x1, 0x18e3, 0x800, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x800, 0x18e3, 0xc618, 0x18e3, 0x800, 0x1, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x18e3, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x800, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1
};

static Texture eternal_heart {
  13,
  12,
  eternal_heart_data
};

#endif