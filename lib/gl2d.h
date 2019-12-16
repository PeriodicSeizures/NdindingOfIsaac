#ifndef GL2D_H
#define GL2D_H

#include <stdint.h>
#include "vector.h"
using namespace std;

struct Texture
{
    uint16_t width; 
    uint16_t height;
    uint16_t *bitmap;
    //COLOR
};

struct Pixels
{
    uint16_t *bitmap;
};

//struct Animation
//{
//    uint16_t width;
//    uint16_t height;
//    uint16_t count;
//    Pixels *frames;
//};

struct Animation
{
    uint16_t width;
    uint16_t height;
    uint16_t count;
    uint16_t *frames;
};

    //use class or struct for sprite???
    //
    //should use struct ?
    //
    //either use struct


    
    
    //if methods are overridden, will consume too much memory
    //+ all methods will have similar behavior (no need for override)
    //+ how to key certain animations -> string
    //could create enum with RIGHT, UP, LEFT, DOWN ---> as index
    //and map each anim ptr to that certain array[index]
    


// Sprite Animation Properties (effects / post-processing)
// for instance :
//  - Trembling (animation rapidly shakes randomly) shake -> 
//  - Rotating (animation might rotate) <- might be unnecessary
//  - Tracking (animation might face another Sprite; sub-property)
//  - Shadow
//  - ?

//enum Direction {
//    RIGHT = 0, UP = 90, LEFT = 180, DOWN = 270
//};

/*
class Sprite
{
	public:
		Vector2 position;
        Vector2 velocity;
        
        Direction dir;
        uint8_t currentFrame;
        
        // are pointrts to texture and animation
        Texture *activeTexture; // PTR to texture
        Animation *activeAnimation; // PTR to animation
        
        // are pointers to textures and arrays of animations
        Texture *assignedTextures; // PTR to array! [] (could be referenced by <dir> value)
        Animation *assignedAnimations; // PTR to array! [] (must be with <dir> value)

		Sprite();
		Sprite(int x, int y);
        //Sprite(int x, int y, int z);

        void addTexture(Direction dir, Texture *texture);
        void addAnimation(Direction dir, Animation *animation);

        //void set(int x, int y);
        //void reset();
		
        //float getVelocity();

        Direction getDirection();
		
        //void move(int relX, int relY);
        //void moveTo(int x, int y);
        void move(Vector2 rel);
        void moveTo(Vector2 pos);

        void updateAnimations(); // Scrolls through animations / cycles

        void setAnimDirSeq(Direction dir);

        //void cycleAnimation(string key);
        //void cycleAnimation(string key, unsigned int frame);
        
};*/

#endif