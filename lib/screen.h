#ifndef SCREEN_H
#define SCREEN_H

#include <os.h>
#include <iostream>
#include <libndls.h>
//#include <vector>

#include "gl2d.h"

// extern because will be defined externally
extern scr_type_t type;
extern unsigned int size;
extern uint8_t *screen;



void scr_init();

void scr_uninit();

void scr_setPixel(uint16_t color, unsigned int pitch);

void scr_setPixel(uint16_t color, int screenX, int screenY);

void scr_setPixel(uint8_t r, uint8_t g, uint8_t b, 
    int screenX, int screenY);

void scr_flip();

void scr_fill(uint8_t r, uint8_t g, uint8_t b);

void scr_fillRect(uint8_t r, uint8_t g, uint8_t b, 
    unsigned int screenX, unsigned int screenY, unsigned int w, unsigned int h);

//void scr_drawPixels(uint16_t *bitmap, uint16_t w, uint16_t h, int screenX, int screenY);

void scr_drawTexture(Texture *tex, int screenX, int screenY, bool center=false);

//void scr_drawPixelsMap(uint16_t *bitmap, uint16_t w, uint16_t h, int screenX, int screenY, );
void scr_drawAnimationFrame(Animation *anim, int screenX, int screenY, unsigned int frame, bool center=false);



#endif