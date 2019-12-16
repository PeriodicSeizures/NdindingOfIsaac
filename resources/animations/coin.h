#include "../lib/gl2d.h"

static uint16_t coinData[] = {
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 44406, 35654, 2048, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 33873, 44406, 29381, 2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 1, 
    2048, 2048, 29381, 33873, 44406, 35654, 2048, 29381, 35654, 35654, 35654, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 33873, 44406, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 29381, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 29381, 29381, 29381, 29381, 29381, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 29381, 33873, 44406, 44406, 35654, 29381, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 35654, 35654, 33873, 44406, 44406, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 1, 
    2048, 2048, 29381, 35654, 35654, 33873, 44406, 44406, 35654, 35654, 35654, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 29381, 35654, 33873, 44406, 44406, 2048, 2048, 2048, 2048, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 2048, 33873, 44406, 44406, 35654, 29381, 2048, 29381, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 29381, 29381, 29381, 29381, 29381, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 29381, 35654, 2048, 35654, 33873, 44406, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 35654, 35654, 29381, 2048, 2048, 33873, 44406, 44406, 44406, 35654, 29381, 2048, 2048, 1, 
    2048, 2048, 29381, 35654, 35654, 35654, 2048, 29381, 33873, 44406, 44406, 44406, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 29381, 35654, 35654, 35654, 29381, 33873, 44406, 44406, 44406, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 2048, 29381, 35654, 35654, 33873, 44406, 44406, 44406, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 44406, 44406, 44406, 29381, 29381, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 29381, 35654, 2048, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 35654, 35654, 29381, 2048, 2048, 2048, 29381, 35654, 33873, 44406, 44406, 2048, 2048, 1, 
    2048, 2048, 29381, 35654, 35654, 35654, 2048, 29381, 35654, 35654, 35654, 33873, 44406, 44406, 35654, 29381, 2048, 2048, 
    2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 33873, 44406, 44406, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 33873, 44406, 44406, 35654, 35654, 29381, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 29381, 29381, 33873, 44406, 44406, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 29381, 35654, 2048, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 35654, 35654, 29381, 2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 1, 
    2048, 2048, 29381, 35654, 35654, 35654, 2048, 29381, 35654, 35654, 35654, 35654, 35654, 35654, 35654, 33873, 2048, 2048, 
    2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 35654, 35654, 35654, 33873, 44406, 2048, 2048, 
    2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 29381, 35654, 35654, 35654, 33873, 44406, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 29381, 29381, 29381, 29381, 29381, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 2048, 2048, 2048, 2048, 29381, 35654, 2048, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 1, 1, 
    1, 2048, 2048, 29381, 35654, 35654, 29381, 2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 1, 
    2048, 2048, 29381, 35654, 35654, 35654, 2048, 29381, 35654, 35654, 35654, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 2048, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 
    2048, 2048, 2048, 29381, 35654, 35654, 35654, 29381, 2048, 29381, 35654, 35654, 35654, 35654, 29381, 2048, 2048, 2048, 
    2048, 2048, 23076, 2048, 2048, 2048, 29381, 29381, 29381, 29381, 29381, 29381, 2048, 2048, 2048, 23076, 2048, 2048, 
    1, 2048, 2048, 23076, 29381, 29381, 2048, 2048, 2048, 2048, 2048, 2048, 29381, 29381, 23076, 2048, 2048, 1, 
    1, 1, 2048, 2048, 2048, 2048, 23076, 29381, 29381, 29381, 29381, 23076, 2048, 2048, 2048, 2048, 1, 1, 
    1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 2048, 2048, 2048, 2048, 2048, 2048, 1, 1, 1, 1, 1, 1
};

static Animation coin {
    18,
    12,
    6,
    coinData
};