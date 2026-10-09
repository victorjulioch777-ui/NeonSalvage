#include "neon_core.h"

uint32_t nc_xorshift32(uint32_t *state)
{
    if (state == 0){
        return 0;
    }
    
    if (*state == 0){
        *state = 0xA341316Cu;
    }

    uint32_t x = *state;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    *state = x;

    return x;
}

int nc_manhattan_distance(NC_Point a, NC_Point b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    if (dx < 0){
        dx = -dx;
    }

    if (dy < 0){
        dy = -dy;
    }

    return dx + dy;
}