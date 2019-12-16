// simpler implementation for items
// items.h
#ifndef ITEMS_H
#define ITEMS_H

#include "../../lib/gl2d.h"
//#include "../entities/entity.h"

/*
    Item class acts as enum for basic Item data
*/

class Item {

    public:
        const char *name;
        const char *description;
        Texture *texture;

        Item(const char *name, const char *description, Texture *texture);

        //const char *getName();
        //const char *getDescription();
        //virtual void onThisCollect();
        virtual void onCollect();
        //virtual void onThisUse
        //int getRechargeTime() {return this->rechargeTime;}
        void onFireTear(/* put tear entity here */);
        void onTearCollide(/* put tear entity here */);
        void onPlayerDamaged(/* put damage, source here */);
        void onPlayerCollect(/* put collected here */);
        void onPlayerEntityCollide(/* put entity here */);
        void onRoomSwitch(/* put room data here */);
        void onBombDetonate(/* put detonate data here */);
        //virtual void onDoorUnlock(/* put room/door data here */) {}
        //virtual void onKeyUse(/* put unlocked data here */) {}
        //virtual void onItemUse(/* put item data here */) {}
        void onHostileDeath(/* put death data here */);
        void onPlayerDeath(/* put death data here */);
        //virtual void onCardUse(/* put card data here */) {}
        void onRoomClear(/* put room data here */);
        void onNewRoomEnter();
};

class ActiveItem : public Item {
    public:
        const unsigned int rechargeCount;
        unsigned int chargeCount;
        //ActiveItem(const char *name, const char *description, unsigned int rechargeCount) : Item(name, description) {
        //    this->rechargeCount = rechargeCount;
        //}

        ActiveItem(const char *name, const char *description, Texture *texture, const unsigned int rechargeCount); // : RegistryItem(name, description);

        void onActivate(/*EntityPlayer *player*/);
};

class ConsumableItem : public Item {
    public:
        //ActiveItem(const char *name, const char *description, unsigned int rechargeCount) : Item(name, description) {
        //    this->rechargeCount = rechargeCount;
        //}

        ConsumableItem(const char *name, const char *description, Texture *texture); // : RegistryItem(name, description);

        void onUse(/*EntityPlayer *player*/);
};

/*
class Trinket : public Item {
    public:
        const unsigned int rechargeCount;
        //ActiveItem(const char *name, const char *description, unsigned int rechargeCount) : Item(name, description) {
        //    this->rechargeCount = rechargeCount;
        //}

        ActiveItem(const char *name, const char *description, Texture *texture, const unsigned int rechargeCount); // : RegistryItem(name, description);
};*/

//class 


#endif