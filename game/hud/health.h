// stats (heart)...
#ifndef HEALTH_H
#define HEALTH_H

class Health {
    public:
        static const Health HEART_CONTAINER;
        static const Health HEART_CONTAINER_HALF;
        static const Health SOUL_HEART;
        static const Health SOUL_HEART_HALF;
        static const Health BLACK_HEART;
        static const Health BLACK_HEART_HALF;
        static const Health ETERNAL_HEART;

        //static const Health GOLD_HEART;
        //static const Health BONE_HEART;

        //char *name;
        Texture *texture;
        //unsigned int priority;

    private:
        Health(Texture *texture); //, unsigned int priority);
};

#endif