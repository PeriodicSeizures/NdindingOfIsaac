// room class declaration

#ifndef ROOM_H
#define ROOM_H

#include <time.h>
#include <vector>

#include "../../lib/util.h"
#include "../entities/entity.h"

#define MAP_SIZE 15

#define ROOM_WIDTH 13
#define ROOM_HEIGHT 7

#define TILE_PIXEL_WIDTH 19
#define TILE_PIXEL_HEIGHT 21

#define MIN_PIXEL_X 32
#define MIN_PIXEL_Y 51
#define MAX_PIXEL_X 287
#define MAX_PIXEL_Y 188

// room types
enum RoomType {
    NORMAL, 
    BOSS, TREASURE, SHOP, ARCADE,
    NORMAL_CHALLENGE, BOSS_CHALLENGE, CURSE,
    SACRIFICE, SECRET, SUPER_SECRET,
    LIBRARY, DEVIL, ANGEL, VAULT, DICE, BEDROOM, CRAWL_SPACE,
    BLACK_MARKET, I_AM_ERROR, BOSS_RUSH, MEGA_SATAN, BLUE_WOMB, // or room "???"
    CLOSET, GRAVE, NONE
};

//enum 

class Room {
    public:
        /*const*/ RoomType roomType;
        /*const*/ unsigned int x;
        /*const*/ unsigned int y;
        unsigned int p;

        std::vector<Entity> entities;
                
        //RoomType *attachedDoors;
        RoomType *doors;

        

        Room(RoomType roomType, unsigned int pitch);
        Room(RoomType roomType, unsigned int x, unsigned int y);

        unsigned int getPitch();
        //Room(RoomType roomType, unsigned int p);
};

//class Room {
//    public:
//        const RoomType roomType;
//        std::vector<Entity> loadedEntities;
//        //bool *doors[4];
//        RoomNode *attachedRooms;
//
//        Room(const RoomType roomType);
//};

//struct Room {
//    //unsigned int x;
//    //unsigned int y;
//    RoomType roomType;
//    std::vector<Entity> *loadedEntities;
//    bool *doors[4];
//};

//struct RoomNode {
//    unsigned int x;
//    unsigned int y;
//    
//    RoomType *doors[4];
//};

class Generator {
    public:
        Random *random;
        //Room *rooms[121]; 
        //std::vector<std::vector<Room>> rooms;
        std::vector<Room> rooms; // in pitch
        
        // array with allocated memory of size 121, because each floor will be 11x11 MAX
        
        // below for unique rooms 
        // (generated only once per floor)
        //bool ARCADE_GENERATED;
        //bool SHOP_GENERATED;
        //bool CURSE_GENERATED;
        //bool SACRIFICE_GENERATED;
        ////bool 
        //bool DICE_GENERATED;
        
        std::vector<RoomType> specialRooms;
        
        unsigned int floor;

    public:
        Generator(int seed = time(0)); // random seed
        //~Generator();

        void generateNewFloor();// use when a new level is to be generated
        void generateNeighbours(Room room); // generate all rooms surrounding a room
};



// create generator function for room, or ...
#endif