#include "item.h"

#include "../../lib/gl2d.h"

//Item::Item() {};

Item::Item(const char *name, const char *description, Texture *texture) {
    this->name = name;
    this->description = description;
    this->texture = texture;
    //this->rechargeTime = 0
}

//const char *Item::getName() {return this->name;}
//const char *Item::getDescription() {return this->description;}
//virtual void onThisCollect();
void Item::onCollect() {}
//virtual void onThisUse
//int getRechargeTime() {return this->rechargeTime;}
void Item::onFireTear(/* put tear entity here */) {}
void Item::onTearCollide(/* put tear entity here */) {}
void Item::onPlayerDamaged(/* put damage, source here */) {}
void Item::onPlayerCollect(/* put collected here */) {}
void Item::onPlayerEntityCollide(/* put entity here */) {}
void Item::onRoomSwitch(/* put room data here */) {}
void Item::onBombDetonate(/* put detonate data here */) {}
//virtual void onDoorUnlock(/* put room/door data here */) {}
//virtual void onKeyUse(/* put unlocked data here */) {}
//virtual void onItemUse(/* put item data here */) {}
void Item::onHostileDeath(/* put death data here */) {}
void Item::onPlayerDeath(/* put death data here */) {}
//virtual void onCardUse(/* put card data here */) {}
void Item::onRoomClear(/* put room data here */) {}
void Item::onNewRoomEnter() {}



ActiveItem::ActiveItem(const char *name, const char *description, Texture *texture, const unsigned int rechargeCount) : 
    Item(name, description, texture), rechargeCount(rechargeCount) {
    //this->rechargeCount = rechargeCount;
}

void ActiveItem::onActivate(/*EntityPlayer *player*/) {

}



ConsumableItem::ConsumableItem(const char *name, const char *description, Texture *texture) : Item(name, description, texture) {

}

void ConsumableItem::onUse(/*EntityPlayer *player*/) {

}
