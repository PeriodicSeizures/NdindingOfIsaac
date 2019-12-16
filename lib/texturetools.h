// texture tools
// resize, grayscale, negate, fade, mirror, crop, ...
#ifndef TEXTURETOOLS_H
#define TEXTURETOOLS_H

#include "gl2d.h"

//Throws if allocation failed
Texture *newTexture(unsigned int w, unsigned int h, uint16_t *bitmap);

// Use ONLY to delete copies
void deleteTexture(Texture *tex);

//Textures have to have the same resolution
Texture *copyTexture(Texture *tex);

/*
    Texture Operations
     (Photoshopping)
*/

uint16_t getPixel(Texture *tex, int x, int y);

//Returns negated texture
Texture *negatedTexture(Texture *tex);

//Returns resized texture
//Texture *resizedTexture( Texture *tex, uint16_t w, uint16_t h);

//Returns greyscale texture 
Texture *greyscaledTexture(Texture *tex);

#endif // TEXTURETOOLS_H
