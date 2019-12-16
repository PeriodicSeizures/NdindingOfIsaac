#include <os.h>
#include <iostream>
#include <libndls.h>
#include <vector>
#include <algorithm>

#include "screen.h"
#include "gl2d.h"

scr_type_t type;
unsigned int size;
uint8_t *screen;

void scr_init()
{
    type = SCR_320x240_565;
    size = 320*240 * 2;
    screen = new uint8_t[size];
    scr_fill(255, 255, 255);
}

void scr_uninit() {
    std::cout << "Unititializing screen..." << "\n";
    delete[] screen;
    lcd_init(SCR_TYPE_INVALID);
    std::cout << "Unititialized screen!" << "\n";
}

void scr_setPixel(uint16_t c, unsigned int pitch) {
    // On color models, each pixel is represented in 16-bit high color
    // On classic models, each pixel is 4 bits grayscale, 0 is black and 15 is white

	//int a,b;
	//a = (int)screenX; b = (int)screenY

    //if (a < 320 && b < 240 ) {
        //unsigned int pos = screenY * SCREEN_WIDTH + screenX;
    reinterpret_cast<uint16_t*>(screen)[pitch] = c;
    
}

void scr_setPixel(uint16_t c, int screenX, int screenY) {
    // On color models, each pixel is represented in 16-bit high color
    // On classic models, each pixel is 4 bits grayscale, 0 is black and 15 is white

	//int a,b;
	//a = (int)screenX; b = (int)screenY

    if (screenX >= 0 && screenY >= 0 && screenX < 320 && screenY < 240) {
    //if (a < 320 && b < 240 ) {
        unsigned int pos = screenY * SCREEN_WIDTH + screenX;
        //unsigned int pos = screenY * SCREEN_WIDTH + screenX;
        reinterpret_cast<uint16_t*>(screen)[pos] = c;
    }
}

void scr_setPixel(uint8_t r, uint8_t g, uint8_t b, int screenX, int screenY) {
    // On color models, each pixel is represented in 16-bit high color
    // On classic models, each pixel is 4 bits grayscale, 0 is black and 15 is white

	//int a,b;
	//a = (int)screenX; b = (int)screenY

    if (screenX >= 0 && screenY >= 0 && screenX < 320 && screenY < 240) {
    //if (a < 320 && b < 240 ) {
        unsigned int pos = screenY * SCREEN_WIDTH + screenX;
        //unsigned int pos = screenY * SCREEN_WIDTH + screenX;
        reinterpret_cast<uint16_t*>(screen)[pos] = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
    }
}

void scr_flip()
{
    lcd_blit(screen, type);
}

void scr_drawHorzLine(uint8_t r, uint8_t g, uint8_t b, int x1, int y1, int x2)
{
    for (int screenX=x1;screenX<x2;screenX++) scr_setPixel(r, g, b, screenX, y1);
}

void scr_fill(uint8_t r, uint8_t g, uint8_t b) 
{
    uint16_t color;
    color = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);

    std::fill(reinterpret_cast<volatile uint16_t*>(screen), reinterpret_cast<volatile uint16_t*>(screen + size), color);
}

void scr_fillRect(uint8_t r, uint8_t g, uint8_t b, unsigned int screenX, unsigned int screenY, unsigned int w, unsigned int h) {
    for (unsigned int i = screenX; i < screenX + w; i++) {
        for (unsigned int j = screenY; j < screenY + h; j++) {
            scr_setPixel(r, g, b, i, j);
        }
    }
}

//void scr_drawPixels(uint16_t *bitmap, uint16_t w, uint16_t h, int screenX, int screenY) {
//    const unsigned int pixels = w*h;
//
//    //printf("Location 3.1");
//
//    if (w == 320 && h == 240 && screenX == 0 && screenY == 0) {
//        for (unsigned int i = 0; i < pixels; ++i) { // ++i better?
//            if (bitmap[i] != 1)
//                scr_setPixel(bitmap[i], i);
//        }
//        return;
//    }
//
//    //printf("Location 3.2");
//
//    unsigned int pitch = 0;
//    for (unsigned int iy = 0; iy < h; iy++) {
//        for (unsigned int ix = 0; ix < w; ix++) {
//            //draw plus screenX,screenY
//            //if (((int)ix)+screenX >= 0 && ((int)iy)+screenY >= 0)
//            if (pitch < pixels && bitmap[pitch] != 1)
//                scr_setPixel(bitmap[pitch], ix+screenX, iy+screenY);
//            pitch++;
//        }
//
//    }
//
//    //printf("Location 3.3");
//
///*
//    for (unsigned int i = 0; i < numPixels; ++i) {
//        scr_setPixel(tex->bitmap[i], i);
//    }
//*/
//}


void scr_drawTexture(Texture *tex, int screenX, int screenY, bool center) {
    unsigned int pitch = 0;

    const unsigned int pixels = tex->width * tex->height;

    int addX = 0;
    int addY = 0;
    if (center) {
        addX = -tex->width/2;
        addY = -tex->height/2;
    }

    for (int iy = addY; iy < tex->height+addY; iy++) {
        for (int ix = addX; ix < tex->width+addX; ix++) {
            //draw plus screenX,screenY
            //if (((int)ix)+screenX >= 0 && ((int)iy)+screenY >= 0)
            if (pitch < pixels && tex->bitmap[pitch] != 1)
                scr_setPixel(tex->bitmap[pitch], ix+screenX, iy+screenY);
            pitch++;
        }

    }

/*
    for (unsigned int i = 0; i < numPixels; ++i) {
        scr_setPixel(tex->bitmap[i], i);
    }
*/
}

void scr_drawAnimationFrame(Animation *anim, int screenX, int screenY, unsigned int frame, bool center) {
    if (anim->count <= frame) return;

    //unsigned int endPitch = startPitch + anim->width * anim->height;

    const unsigned int pixels = anim->width * anim->height;

    const unsigned int startPitch = pixels * frame; //anim->frames[frame]
    unsigned int pitch = startPitch;

    int addX = 0;
    int addY = 0;
    if (center) {
        addX = -anim->width/2;
        addY = -anim->height/2;
    }

    for (int iy = addY; iy < anim->height+addY; iy++) {
        for (int ix = addX; ix < anim->width+addX; ix++) {
            //draw plus screenX,screenY
            //if (((int)ix)+screenX >= 0 && ((int)iy)+screenY >= 0)
            if (pitch < startPitch + pixels && anim->frames[pitch] != 1)
                scr_setPixel(anim->frames[pitch], ix+screenX, iy+screenY);
            pitch++;
        }

    }
}