#ifndef SOLID_ROCK_H
#define SOLID_ROCK_H

#include "../entity.h"

class Rock : public Entity {
    public:
        Rock(unsigned int x, unsigned int y, unsigned int roomX, unsigned int roomY);
};

#endif