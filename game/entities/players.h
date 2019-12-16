// playable characters

#ifndef PLAYERS_H
#define PLAYERS_H

#include "entity.h"

//class IsaacTransform {
//    public:
//        static const IsaacTransform GUPPY;
//        static const IsaacTransform BEELZEBUB;
//        static const IsaacTransform MOM;
//        static const IsaacTransform LEVIATHAN;
//        static const IsaacTransform SERAPHIM;
//        static const IsaacTransform BOB;
//        static const IsaacTransform FUN_GUY;
//        static const IsaacTransform CONJOINED;
//        static const IsaacTransform SPUN;
//        static const IsaacTransform OH_CRAP;
//        static const IsaacTransform SUPER_BUM;
//        static const IsaacTransform BOOK_WORM;
//        static const IsaacTransform SPIDER_BABY;
//        static const IsaacTransform ADULTHOOD;
//        static const IsaacTransform STOMPY;
//
//    private:
//        
//}

class EntityIsaac : public EntityLiving {
    private:
        std::vector<Item> inventory;
        int coinCount;
        int bombCount;
        int keyCount;
        ActiveItem *activeItem;
        std::vector<Item> trinkets;
        std::vector<ConsumableItem> consumables; // cards, pills, runes

        Animation *legMoveRight;
        Animation *legMoveHoriz;
        Animation *legMoveLeft;
        
        //Animation *move
        Texture *headRight;
        Texture *headUp;
        Texture *headLeft;
        Texture *headDown;

        Texture *headFireRight;
        Texture *headFireUp;
        Texture *headFireLeft;
        Texture *headFireDown;

        float damage;
        float movementSpeed;
        float tearSpeed;
        float fireSpeed;
        float tearRange;
        float luck;
        float faith;
        float evil;

        //std::vector<Health> otherHealth;

    public:
        void controls();

        void onAnimate();

        EntityIsaac(unsigned int x, unsigned int y, 
                unsigned int roomX, unsigned int roomY);       
};



#endif