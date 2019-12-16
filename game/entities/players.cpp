#include <os.h>
#include <libndls.h>

#include "players.h"
#include "entity.h"

#include "../../lib/screen.h"

#include "../../resources/animations/isaac/isaac_walk_horiz.h"
#include "../../resources/animations/isaac/isaac_walk_right.h"
#include "../../resources/animations/isaac/isaac_walk_left.h"

#include "../../resources/textures/isaac/head_up.png.h"
#include "../../resources/textures/isaac/head_right.png.h"
#include "../../resources/textures/isaac/head_left.png.h"
#include "../../resources/textures/isaac/head_down.png.h"
#include "../../resources/textures/isaac/fire_up.png.h"
#include "../../resources/textures/isaac/fire_right.png.h"
#include "../../resources/textures/isaac/fire_left.png.h"
#include "../../resources/textures/isaac/fire_down.png.h"

EntityIsaac::EntityIsaac(unsigned int x, unsigned int y, 
        unsigned int roomX, unsigned int roomY) : EntityLiving(x, y, roomX, roomY, 6) {

    this->bombCount = 1;

    this->legMoveRight = &isaac_walk_right;
    this->legMoveHoriz = &isaac_walk_horiz;
    this->legMoveLeft = &isaac_walk_left;
    
    //Animation *move
    this->headRight = &head_right;
    this->headUp = &head_up;
    this->headLeft = &head_left;
    this->headDown = &head_down;

    this->headFireRight = &fire_right;
    this->headFireUp = &fire_up;
    this->headFireLeft = &fire_left;
    this->headFireDown = &fire_down;

    this->damage        = 3.50;
    this->movementSpeed = 1.00;
    this->tearSpeed     = 1.00;
    this->fireSpeed     = 8.00;
    this->tearRange     = 23.75;
    this->luck          = 0.00;
    this->faith         = 0.00;
    this->evil          = 0.00;

    this->direction = Direction::UP;

}

const int delay = 5;
const int headVertOffset = -15;

void EntityIsaac::onAnimate() {

    bool m = isKeyPressed(KEY_NSPIRE_W) || 
        isKeyPressed(KEY_NSPIRE_S) || 
        isKeyPressed(KEY_NSPIRE_D) || 
        isKeyPressed(KEY_NSPIRE_A);



    switch(direction) {

        case Direction::RIGHT: 
            scr_drawAnimationFrame(&isaac_walk_right,
                x, y, frame/delay, true);

            scr_drawTexture(&head_right, x, y+headVertOffset, true);
            break;
        case Direction::UP: 
            scr_drawAnimationFrame(&isaac_walk_horiz,
                x, y, frame/delay, true);

            scr_drawTexture(&head_up, x, y+headVertOffset, true);
            break;
        case Direction::LEFT: 
            scr_drawAnimationFrame(&isaac_walk_left,
                x, y, frame/delay, true);

            scr_drawTexture(&head_left, x, y+headVertOffset, true);
            break;
        case Direction::DOWN: 
            scr_drawAnimationFrame(&isaac_walk_horiz,
                x, y, frame/delay, true);

            scr_drawTexture(&head_down, x, y+headVertOffset, true);
            break;
        //default: frame = 0; return;

    }

    if (!m) {
        //scr_drawAnimationFrame(&isaac_walk_horiz,
        //    x, y, 0);
        frame = 0; 
        return;
    }

    frame++;

    if (frame >= isaac_walk_horiz.count*delay) frame = 0;

}

void EntityIsaac::controls() {
    bool w = isKeyPressed(KEY_NSPIRE_W);
    bool s = isKeyPressed(KEY_NSPIRE_S);

    if (w) {
        move(0, -1); //y--; 
        direction = Direction::UP;
    } else if (s) {
        move(0, 1); //y++;
        direction = Direction::DOWN;
    } else direction = Direction::DOWN;

    if (isKeyPressed(KEY_NSPIRE_A)) {
        move(-1, 0); //x--;
        if (!w && !s) direction = Direction::LEFT;
    } else if (isKeyPressed(KEY_NSPIRE_D)) {
        move(1, 0); //x++;
        if (!w && !s) direction = Direction::RIGHT;
    }

    //if (isKeyPressed(KEY_NSPIRE_Q)) active

    //if (isKeyPressed(KEY_NSPIRE_LEFT)) shoot

}