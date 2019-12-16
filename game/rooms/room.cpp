// rooms code

#include "room.h"
#include "../../lib/util.h"

#include <iostream>
#include <vector>
#include <utility>

#include "../entities/immovable/rock.h"

#include "../../lib/screen.h"

#define CLAMP(i, a, b) (i<a) ? a : (i>b) ? b : i

//#include ../../lib/vector.h"

//#define SIZE 11

//Room::Room(RoomType roomType, int x, int y) 
//    : roomType(roomType), x(x), y(y) {
//    this->entities = {};
//    this->attachedDoors[4]; 
//}

//Room::Room(RoomType roomType, int x, int y) {
//    this->roomType = roomType;
//    this->entities = {};
//    this->doors[4];
//    this->x = x;
//    this->y = y;
//}

//Room::Room(RoomType roomType, unsigned int p) {
//    this->roomType = roomType;
//    this->entities = {};
//    this->doors[4];
//    this->p = p;
//}

Room::Room(RoomType roomType, unsigned int x, unsigned int y) {
    this->roomType = roomType;
    this->entities = {};
    this->doors[4];
    //this->p = MAP_SIZE*y + x;
    this->x = x;
    this->y = y;

}

unsigned int Room::getPitch() {
    return y*MAP_SIZE + x;
}



Generator::Generator(int seed) {
    this->random = new Random(seed);
    //this->floor = 0;
    //this->rooms = new Room[100];
    //generateNewFloor();

    //this->rooms.assign(MAP_SIZE * MAP_SIZE, Room(RoomType::NONE, 0, 0));

    for (unsigned int y=0; y<MAP_SIZE; y++) {
        for (unsigned int x=0; x<MAP_SIZE; x++) {
            this->rooms.push_back(Room(RoomType::DEVIL, x, y));
        }
    }

    rooms[0].entities.push_back(Rock(0, 0, 0, 0));
}

void Generator::generateNewFloor() {
    std::cout << "Generating new floor\n";
    
    const unsigned int roomCount = 8 + floor*2 + random->nextInt(4);
    
    const unsigned int treasureRoomCount = random->nextInt(CLAMP(floor+2, 1, 4)) + 1;
    const unsigned int genArcade = floor > 0 && random->nextInt(3)==0;
    
    unsigned int remaining = roomCount;

    const unsigned int secretRoomCount = random->nextInt(2) + floor/2 + 1;
    const unsigned int superSecretRoomCount = random->nextInt(2) + (floor+1)/3;
    
    //const unsigned int 

    //const unsigned int mainSplitCount

    int c = 0;
    unsigned int x; //, y;
    unsigned int y;
    while (c < roomCount) {
        // generate like outwards spreading branches

        // if first room, must gen 3-4 branches
        if (c==0) {
            // random [3, 4]
            const unsigned int splitCount = random->nextInt(2) + 3;

            
        } else {
            // generate 0-3 branches
            const unsigned int splitCount = random->nextInt(4);

            //for (
            

        }
        // start at spawn-room
    }
    
    //for (int i=0; i<roomCount; i++

    // generate
    this->rooms.clear();
    //this->rooms = new Room(RoomType::NONE)[SIZE*SIZE];
    //this->rooms
    for (unsigned int i=0; i<MAP_SIZE*MAP_SIZE; i++) {
        this->rooms.push_back(Room(RoomType::NONE, 0, 0));
    }
    //this->rooms.assign(MAP_SIZE * MAP_SIZE, Room(RoomType::NONE, 0, 0));

    std::cout << "Pushed elements\n";

    //for (

    // ONLY 0 for tests
    unsigned int center = 0;

    //unsigned int center = MAP_SIZE*(MAP_SIZE/2)*(MAP_SIZE/2+1); //11*5+6; // average center of map

    //Room *room = new Room();

    //this->rooms[center] = room;

    //specialRooms.push_back();
    specialRooms.push_back(BOSS);
    specialRooms.push_back(TREASURE);
    specialRooms.push_back(SHOP);
    specialRooms.push_back(ARCADE);

    //generateNeighbours(this->rooms[center]);

}

std::pair<int, int> tan(unsigned int r) {
    switch (r%360) {
        case 0:     return std::make_pair(1, 0);
        case 45:    return std::make_pair(1, 1);
        case 90:    return std::make_pair(0, 1);
        case 135:   return std::make_pair(-1, 1);
        case 180:   return std::make_pair(-1, 0);
        case 225:   return std::make_pair(-1, -1);
        case 270:   return std::make_pair(0, 1);
        case 315:   return std::make_pair(1, -1);
    }
    return {0,0};
}//return std::make_pair(


void Generator::generateNeighbours(Room room) { // generate all rooms surrounding a room
//    // test whether room is near
//    std::cout << "Generating neighbour(s)\n";
//    
//    unsigned int r=0;
//
//    //for (unsigned int r=0; r<360; r+=45) {
//
//        // room x,y is negative for unknown reason
//        std::cout << "room : " << room.x << " " << room.y << "\n";
//
//        std::pair<int,int> t = tan(r);
//        
//        std::cout << "tan : " << t.first << " " << t.second << "\n";
//
//        int x = (int)room.x + t.first;
//        int y = (int)room.y + t.second;
//
//        std::cout << "final : " << x << " " << y << "\n";
//        
//        // if not on borders of map
//        if (x>=0 && y>=0 && x<MAP_SIZE && y<MAP_SIZE) {
//            
//            // chance for whether a room will generate here
//            
//            int c = random->nextInt(2);
//            
//            std::cout << "Chance : " << c << "\n";
//            
//            if (c==0) {
//                // generate room type
//
//                if (specialRooms.size() > 0) {
//
//                    // whether to generate a special room
//                    if (random->nextInt(2)==0) {
//                        switch(random->nextInt(3)) {
//                            case 0: 
//                                std::cout << "Generating treasure room\n";
//                                break;
//                            case 1: 
//                                std::cout << "Generating secret room\n";
//                                break;
//                            case 2: 
//                                std::cout << "Generating super secret room\n";
//                                break;
//                        }
//                    } else std::cout << "Generating normal room\n";
//
//                    //std::cout << "Generating " << availableUniqueRooms[random.nextInt(availableUniqueRooms.size())] << "\n";
//                }
//            }
//            //this->rooms[y*MAP_SIZE + x] = this->random.nextInt();
//            
//        }
//    //}
    
}
