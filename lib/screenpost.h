// postprocessing of screen

/*
postprocessing filters / effects

these should be inserted in a different header/file, 
*/
#ifndef SCREENPOST_H
#define SCREENPOST_H

#include <stdint.h>

void scr_postOverlay(uint8_t r, uint8_t g, uint8_t b, uint8_t intensity);

void scr_postPixelate(uint8_t intensity);

#endif