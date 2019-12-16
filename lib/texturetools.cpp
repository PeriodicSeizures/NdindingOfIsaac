#include <stdint.h>
#include <iterator>
#include <iostream>
#include <os.h>
#include <libndls.h>
#include <bitset>

#include "texturetools.h"
#include "gl2d.h"

Texture *newTexture(uint16_t w, uint16_t h) {
    // TODO: Don't leak on exception
    Texture* tex = new Texture;

    tex->width = w;
    tex->height = h;

    tex->bitmap = new uint16_t[w * h]{0};

    return tex;
}

// Use ONLY to delete copies
void deleteTexture(Texture *tex) {
    std::cout << "Deleting texture..." << "\n";
    delete[] tex->bitmap;
    delete tex;
    std::cout << "Deleted texture!" << "\n";
}

Texture *copyTexture(Texture *tex) {//, Texture &dest)

    Texture *copy = newTexture(tex->width, tex->height);

    std::copy(tex->bitmap, tex->bitmap + tex->width*tex->height, copy->bitmap);

    return copy;
}

/*
void drawTexture(const Texture &tex,
				 uint16_t x, uint16_t y) {
}
*/


/*

    "Photoshopping"

*/

// uint16_t
uint16_t getPixel(Texture *tex, int x, int y) { 
    return tex->bitmap[y + y*x]; 
}



//Returns negated texture
Texture* negatedTexture(Texture *tex) {
    const unsigned int numPixels = tex->width * tex->height;

    Texture *copy = newTexture(tex->width, tex->height);

    for (unsigned int i = 0; i < numPixels; ++i) {
        const uint16_t rgb16 = tex->bitmap[i];

        const uint8_t red8      = 0b11111111 - (((rgb16 >> 8)   ) & 0b11111000);
        const uint8_t green8    = 0b11111111 - (((rgb16 >> 3)   ) & 0b11111100);
        const uint8_t blue8     = 0b11111111 - (((rgb16 << 3)   ) & 0b11111111);

        const uint16_t newColor = ((red8 >> 3) << 11) | ((green8 >> 2) << 5) | (blue8 >> 3);

        //const RGB rgb = rgbColor(tex.bitmap[i]);
        //copy.bitmap[i] = (rgb.r.value + rgb.g.value + rgb.g.value + rgb.b.value) >> 5;
        copy->bitmap[i] = newColor;

    }
    
    return copy;

}

// Current state will crash program
// Returns resized texture (factor 0-100)
/*
Texture *resizedTexture(const Texture *tex, uint16_t w, uint16_t h) {

    if (tex->width == w && tex->height == h) return copyTexture(tex);

    //const unsigned int numPixels = tex->width * tex->height;

    Texture *copy = newTexture(w, h);

    // get original width of image, compare to w

    for (float x=0; x < tex->width; x+=(tex->width/w)) {
        for (float y=0; y < tex->height; y+=(tex->height/h)) {
            
            const unsigned int pitch = (int)y + (int)y * (int)x;

            const uint16_t rgb16 = tex->bitmap[pitch];

            copy->bitmap[pitch] = rgb16;

        }
    }
    
    return copy;
}*/

//#define debug

Texture *greyscaledTexture(Texture *tex) {
    const unsigned int numPixels = tex->width * tex->height;

    Texture *copy = newTexture(tex->width, tex->height);

    //bool lastPressed = false;

    for (unsigned int i = 0; i < numPixels; ++i) {
        const uint16_t rgb16 = tex->bitmap[i];

        const uint8_t red8      = ((rgb16 >> 8)   ) & 0b11111000;
        const uint8_t green8    = ((rgb16 >> 3)   ) & 0b11111100;
        const uint8_t blue8     = ((rgb16 << 3)   ) & 0b11111111;

        const uint8_t greyChannel     = ((red8+green8+blue8)/3);

        //const uint16_t greyChannel = (((rgb16 >> 11) + ((rgb16 >> 5) & 0b111111) + (rgb16 & 0b11111)) / 3);

        //const uint16_t greyColor = (greyChannel << 8) | (greyChannel << 3) | (greyChannel >> 3);
        const uint16_t greyColor = ((greyChannel >> 3) << 11) | ((greyChannel >> 2) << 5) | (greyChannel >> 3);

        //const RGB rgb = rgbColor(tex.bitmap[i]);
        //copy.bitmap[i] = (rgb.r.value + rgb.g.value + rgb.g.value + rgb.b.value) >> 5;
        copy->bitmap[i] = greyColor;


        /*
            DEBUG
        */

/*
        std::bitset<16> pixelBitset(rgb16);

        std::bitset<16> shiftedRed(rgb16>>8);

        std::bitset<16> redBitset(red8);
        std::bitset<16> blueBitset(green8);
        std::bitset<16> greenBitset(blue8);

        while(true) {
            if (isKeyPressed(KEY_NSPIRE_C)) {
                if (!lastPressed) {
                    //printf("");
                    std::cout << "Bitset : " << pixelBitset << "\n";

                    std::cout << "red shifted 8 : " << shiftedRed << "\n";

                    std::cout << "red : " << redBitset << "\n";
                    std::cout << "green : " << blueBitset << "\n";
                    std::cout << "blue : " << greenBitset << "\n";

                    std::cout << "\n";

                    lastPressed = true;

                    break;
                }
            } else lastPressed = false;
        }
*/

    }
    
    return copy;
}