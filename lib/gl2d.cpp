#include <stdint.h>
#include "gl2d.h"

/*
Sprite::Sprite() {this->position = Vector2();}
Sprite::Sprite(int x, int y) {this->position = Vector2(x,y);}
//Sprite(int x, int y, int z);

void Sprite::addTexture(Direction dir, Texture *texture) {
    this->assignedTextures[dir] = *texture;// = texture;
}

void Sprite::addAnimation(Direction dir, Animation *animation) {
    this->assignedAnimations[dir] = *animation;
}

//void Sprite::set(int x, int y) {this->x}
//void Sprite::reset() {}

//float Sprite::getVelocity() {}

Direction Sprite::getDirection() {return this->dir;}

void Sprite::move(Vector2 rel) {this->position += rel;}
void Sprite::moveTo(Vector2 pos) {this->position = pos;}

void Sprite::updateAnimations() {
    // update frames; aka just cycle
    if (this->currentFrame < sizeof(this->assignedAnimations)/sizeof(uint16_t)) // correct indexing
        this->currentFrame++;
    else this->currentFrame = 0;
}

void Sprite::setAnimDirSeq(Direction dir) {
    // Change selected either anim or texture
    this->activeAnimation = &(this->assignedAnimations)[dir];
}
*/
//void cycleAnimation(string key);
//void Sprite::cycleAnimation(string key, unsigned int frame);