#ifndef SAD_ONION_H
#define SAD_ONION_H

#include <iostream>

// sad onion
#include "item.h"
#include "../../resources/textures/sad_onion.png.h"

//Item SAD_ONION

//class SadOnion : RegistryItem {
//    
//    public:
//        SadOnion() : RegistryItem("SAD ONION", "Tears up", &sad_onion) {}
//
//    public:
//        void onCollect() {
//            std::cout << "Picked up " << getName() << "\n";
//        }
//};

class ItemSadOnion : public Item {
    
    public:
        ItemSadOnion();

        void onCollect();
};

#endif