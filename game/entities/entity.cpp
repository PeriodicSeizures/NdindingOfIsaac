#include "entity.h"
#include "../rooms/room.h"

#include "../../globals.h"

#define CLAMP(i, a, b) (i<a) ? a : (i>b) ? b : i

Entity::Entity(unsigned int x, unsigned int y, unsigned int roomX, unsigned int roomY, 
        Direction direction, bool breakable, bool solid) {

    this->x = x; 
    this->y = y; 

    this->roomX = roomX;
    this->roomY = roomY;

    this->direction = direction;
    this->breakable = breakable;
    this->solid = solid;
}

//unsigned int Entity::getX() {return this->x;}
//unsigned int Entity::getY() {return this->y;}
//Direction Entity::getDirection() {return this->direction;}
//unsigned int Entity::getRoomX() {return this->roomX;}
//unsigned int Entity::getRoomY() {return this->roomY;}
//bool Entity::isBreakable() {return this->breakable;}
//bool Entity::isSolid() {return this->solid;}
//int Entity::getVelX() {return this->vx;}
//int Entity::getVelY() {return this->vy;}

void Entity::onAnimate() {}

bool Entity::move(int xChange, int yChange) {
    
    unsigned int newX = CLAMP(x+xChange, MIN_PIXEL_X, MAX_PIXEL_X);
    unsigned int newY = CLAMP(y+yChange, MIN_PIXEL_Y, MAX_PIXEL_Y);

    //x = CLAMP(x+xChange, MIN_PIXEL_X, MAX_PIXEL_X);
    //y = CLAMP(y+yChange, MIN_PIXEL_Y, MAX_PIXEL_Y);

    unsigned int tileX = (newX - MIN_PIXEL_X) / TILE_PIXEL_WIDTH;
    unsigned int tileY = (newY - MIN_PIXEL_Y) / TILE_PIXEL_HEIGHT;
    
    for (Entity e : generator.rooms[roomY*MAP_SIZE + roomX].entities) {
        
        // if rock
        if (e.solid) {
            std::cout << "Rock" << "\n";
            // determine tile location of player from x,y

            // tileX = (x - min_pixel_x) / tile_pixel_width

            unsigned int entityTileX = (e.x - MIN_PIXEL_X) / TILE_PIXEL_WIDTH;
            unsigned int entityTileY = (e.y - MIN_PIXEL_Y) / TILE_PIXEL_HEIGHT;

            // now determine whether there is an object at location
            if (entityTileX == tileX && entityTileY == tileY) {
                return false;
            }
    
    
            // then move to / calculate collision
        } else std::cout << "Not a rock" << "\n";
    }

    std::cout << "Entities : " << generator.rooms[roomY*MAP_SIZE + roomX].entities.size() << "\n";

    std::cout << "Player room : " << roomX << " " << roomY << "\n";

    x = newX;
    y = newY;

    return x==MIN_PIXEL_X || x==MAX_PIXEL_X || y==MIN_PIXEL_Y || y==MAX_PIXEL_Y;
    
}




EntityLiving::EntityLiving(unsigned int x, unsigned int y, 
        unsigned int roomX, unsigned int roomY, 
        int maxHealth) : Entity(x, y, roomX, roomY) {

    this->maxHealth = maxHealth;
}

// a ground item
EntityItem::EntityItem(unsigned int x, unsigned int y, 
        unsigned int roomX, unsigned int roomY,
        const Item *item) : Entity(x, y, roomX, roomY), item(item) {

}







EntityHostile::EntityHostile(unsigned int x, unsigned int y, 
        unsigned int roomX, unsigned int roomY,
        int maxHealth) : EntityLiving(x, y, roomX, roomY, maxHealth) {
    
}

//void EntityHostile::onSeePlayer(EntityPlayer *player) {
//    
//}

void EntityHostile::onUpdate() {
    
}
