#ifndef ENTITY_H
#define ENTITY_H

//#include "../items/items.h"

#include <vector>

#include "../items/item.h"
#include "../hud/health.h"

//#include "../../lib/gl2d.h"

//#include <string>

using namespace std;

enum Direction {
    RIGHT = 0, UP = 90, LEFT = 180, DOWN = 270,
};

//enum EntityType {
//    PLAYER, ITEM, MONSTER
//};
//
//enum EntityType {
//    ITEM, MONSTER
//};

// put all items in a saved .TNS file
// for modding purposes?


/*
    all movable objects are entities
    
    either Container, Player, Item, Monster, Projectile, Effect

    Container = chest / tomb / ...
*/

//struct Hitbox {
//    unsigned int w
//    unsigned int h;
//
//    int x;
//    int y;
//};

class Entity {

    //public:
    //  static const Entity E
    public:
        //char *name;
        unsigned int x, y;

        //int health;
        //int maxHealth;

        Direction direction;

        unsigned int roomX, roomY; // what room? (on map)

        bool breakable;
        bool solid;

        unsigned int frame;
        int vx, vy;

        

    public:
        //unsigned int getX();
        //unsigned int getY();
        //
        //Direction getDirection();
        //
        //unsigned int getRoomX();
        //unsigned int getRoomY();
        //
        //bool isBreakable();
        //bool isSolid();
        //
        //int getVelX();
        //int getVelY();
        
        void onAnimate();

        // TO USE COLLISION:
        bool move(int xChange, int yChange);


        Entity(unsigned int x, unsigned int y, unsigned int roomX, unsigned int roomY,
                Direction direction=Direction::RIGHT, bool breakable=true, bool solid=false);

//char *getName();
};

//class Animated {
//    public:
//        unsigned int frame;
//        Animated();
//
//        virtual void onAnimate();
//};

class EntityLiving : public Entity {
    public:
        int health;
        int maxHealth;

        EntityLiving(unsigned int x, unsigned int y, 
                unsigned int roomX, unsigned int roomY,
                int maxHealth);
};



//class EntityTear : public Entity {
//    public:
//        
//};

// a ground item
class EntityItem : Entity {
  public:
    const Item *item;
    //Texture *texture;

    EntityItem(unsigned int x, unsigned int y, 
            unsigned int roomX, unsigned int roomY,
            const Item *item);

};



class EntityHostile : public EntityLiving {
    public:
        void onUpdate();

        EntityHostile(unsigned int x, unsigned int y, 
                unsigned int roomX, unsigned int roomY,
                int maxHealth);

        //void onSeePlayer(EntityPlayer *player);
        

        //void addItem(Item *item);
        //void setItems(Item *items);
        

};



/*
struct Sprite //default
{
    int x;
    int y;

    // are pointrts to texture and animation
    Texture *activeTexture;
    Animation *activeAnimation;
    
    // are pointers to textures and arrays of animations
    Texture *assignedTextures;
    Animation *assignedAnimations;
}*/

#endif