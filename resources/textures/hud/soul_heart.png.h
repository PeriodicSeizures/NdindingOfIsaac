#ifndef SOUL_HEART_PNG_H
#define SOUL_HEART_PNG_H

#include "../../../lib/gl2d.h"

static uint16_t soul_heart_data[] = {
  0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x0, 0x2965, 0x2965, 0x0, 0x1, 0x0, 0x2965, 0x2965, 0x0, 0x1, 0x1, 
  0x1, 0x0, 0x2965, 0x63b4, 0x63b4, 0x2965, 0x0, 0x2965, 0x63b4, 0x63b4, 0x2965, 0x0, 0x1, 
  0x0, 0x2965, 0x63b4, 0xffff, 0xb59a, 0x63b4, 0x2965, 0x63b4, 0xb59a, 0x63b4, 0x63b4, 0x2965, 0x0, 
  0x0, 0x2965, 0x63b4, 0xb59a, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x2965, 0x0, 
  0x0, 0x2965, 0x3a2b, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x3a2b, 0x2965, 0x0, 
  0x1, 0x0, 0x2965, 0x3a2b, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x63b4, 0x3a2b, 0x2965, 0x0, 0x1, 
  0x1, 0x1, 0x0, 0x2965, 0x3a2b, 0x63b4, 0x63b4, 0x63b4, 0x3a2b, 0x2965, 0x0, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x0, 0x2965, 0x3a2b, 0x63b4, 0x3a2b, 0x2965, 0x0, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x0, 0x2965, 0x3a2b, 0x2965, 0x0, 0x1, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x2965, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 
  0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1
};

static Texture soul_heart {
  13,
  12,
  soul_heart_data
};

#endif