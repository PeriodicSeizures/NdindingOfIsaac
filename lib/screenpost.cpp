#include "screenpost.h"
#include "screen.h"

#include <iostream>

void scr_postOverlay(uint8_t r, uint8_t g, uint8_t b, uint8_t intensity) {
    // overlay a screen
    //std::cout << "Color : " <<  screen[0] << "\n";

//    scr_setPixel(255,255,255,0,0);

    // iterate all pixels, and average with r,g,b, with intensity  lerp?

    for (unsigned int p=0; p<320*240; p++) {

        //uint16_t scr_color = 0b1111100000011111;
        uint16_t scr_color = reinterpret_cast<uint16_t*>(screen)[p];

        uint8_t scr_r = (scr_color >> 11) << 3;
        uint8_t scr_g = ((scr_color >> 5) & 0b111111) << 2;
        uint8_t scr_b = (scr_color & 0b11111) << 3;

        //printf("r %u\n", scr_r);
        //printf("g %u\n", scr_g);
        //printf("b %u\n", scr_b);

        uint8_t new_r = scr_r + (uint16_t)(((r-scr_r)*(float)intensity)/256.0);
        uint8_t new_g = scr_r + (uint16_t)(((g-scr_g)*(float)intensity)/256.0);
        uint8_t new_b = scr_b + (uint16_t)(((b-scr_b)*(float)intensity)/256.0);
        
        reinterpret_cast<uint16_t*>(screen)[p] = (new_r << 8) | (new_g << 3) | (new_b >> 3);
    }

    //printf("\n");
    //
    //printf("new-r %u\n", new_r);
    //printf("new-g %u\n", new_g);
    //printf("new-b %u\n", new_b);
    //
    //printf("\n");
    //
    //printf("%u\n", ((new_r << 8) | (new_g << 3) | (new_b >> 3)));


//    for (unsigned int p=0; p<320*240; p++) {
//        uint16_t scr_color = reinterpret_cast<uint16_t*>(screen)[p];
//
//        uint8_t scr_r = (scr_color >> 11) << 3;
//        uint8_t scr_g = ((scr_color >> 5) & 0b111111) << 2;
//        uint8_t scr_b = (scr_color & 0b11111) << 3;
//
//        uint8_t new_r = scr_r + (uint16_t)(((r-scr_r)*(float)intensity)/256.0);
//        uint8_t new_g = scr_r + (uint16_t)(((g-scr_g)*(float)intensity)/256.0);
//        uint8_t new_b = scr_b + (uint16_t)(((b-scr_b)*(float)intensity)/256.0);
//
//        reinterpret_cast<uint16_t*>(screen)[p] = (new_r << 8) | (new_g << 3) | (new_b >> 3);
//    }

    

    printf("%ui\n", reinterpret_cast<uint16_t*>(screen)[0]);
}

void scr_postPixelate(uint8_t intensity) {


}