#include "util.h"

Random::Random(int seed) {
    this->seed = seed;

    this->last1 = seed;
    this->last2 = (seed << 1)*seed;

}

int Random::nextInt(int m) {
    last1 = (16807LL * last2) % 2147483647;
    if (last1 < 0) last1 += 2147483647;
    
    if (last2 < 0) last2 += m*last1;
    
    unsigned int last2Temp = last2;
    
    last2 = ((last1)*2)+1;
    
    return ((last1+last2Temp) >> 1)%m;
}
//void Random::cycle() {next = next + next * 5 + 12345;}
//{next = next * 1103515245 + 12345;}