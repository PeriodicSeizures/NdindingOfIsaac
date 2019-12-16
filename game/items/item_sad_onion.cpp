#include <iostream>

// sad onion
#include "item.h"

#include "item_sad_onion.h"
#include "../../resources/textures/sad_onion.png.h"

ItemSadOnion::ItemSadOnion() : Item("SAD ONION", "Tears up", &sad_onion) {}

void ItemSadOnion::onCollect() {
    std::cout << "Picked up " << name << " (unique print for only sadonion!)\n";
}
