//gamemanager

#include <os.h>
#include <libndls.h>

#include <vector>

#include "gamemanager.h"
//#include "entity.h"

#include "entities/entity.h"
#include "entities/players.h"

#include "rooms/room.h"

//#include "items/items.h"

#include "../lib/screen.h"

#include "items/item.h"

#include "items/item_sad_onion.h"

#include "../resources/textures/rooms/normal.png.h" ///generator/template_room.png.h"
#include "../resources/textures/rooms/devil.png.h"

#include "entities/immovable/rock.h"

#include "../globals.h"

#include "../lib/screenpost.h"

//EntityIsaac isaac;

//Generator generator;

void draw() {
    //scr_fillRect(0,0,0,0,0,320,240);

    unsigned int p = isaac.roomX + isaac.roomY*MAP_SIZE;

    switch(generator.rooms[p].roomType) {
        case RoomType::NORMAL: scr_drawTexture(&normal, 0, 0); break;
        case RoomType::DEVIL: scr_drawTexture(&devil, 0, 0); break;
    }

    isaac.onAnimate();

    //scr_postOverlay(0, 255, 0, 127);

    scr_flip();
}

//void updateInventory() {
//    for (unsigned int i=0; i<isaac.inventory.size(); i++) {
//        
//    }
//}

void newGame() {
    
    // show menu
    // loop

    //generator.rooms[0].entities.push_back(Rock(0, 0, 0, 0));

    //std::vector<Entity> loadedEntities;
    //Room discoveredRooms

    //bool escPressed = false;
    bool spacePressed = false;

    

    //generator.rooms.push_back(Room(RoomType::NORMAL, 0, 0));
    

    while(true) {

        if (isKeyPressed(KEY_NSPIRE_ESC)) return;



        /*
        if (isKeyPressed(KEY_NSPIRE_ESC)) {
            if (!escPressed) {
                escPressed = true;

                //  draw rooms, MOVEMENT, randomness, enemies, tears, items, events, ...
                // MOVEMENT + DRAWING!!!
            }
        } else escPressed = false;*/

        if (isKeyPressed(KEY_NSPIRE_SPACE)) {
            if (!spacePressed) {
                spacePressed = true;
                //mapGen.generateNewFloor();
                

            }
        } else spacePressed = false;
        
        //if (
        isaac.controls();

        draw();

        
        //updateInventory();
        

    }
}

