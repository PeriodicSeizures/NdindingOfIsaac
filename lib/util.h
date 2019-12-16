#ifndef UTIL_H
#define UTIL_H

// util
#include <cstdlib>
#include <time.h>

class Random {
    private:
        unsigned int seed;
        unsigned int last1;
        unsigned int last2;

    public:
        Random(int seed=time(0));
        //int nextInt();
        //int nextIn
        int nextInt(int m=2147483647);
    //private:
    //    void cycle();
};

#endif