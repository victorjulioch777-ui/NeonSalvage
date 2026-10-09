#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "neon_core.h"


static void test_manhattan_distance(void)
{
    NC_Point a = {0, 0};
    NC_Point b = {4, 3};

    int distance = nc_manhattan_distance(a, b);

    assert(distance == 7);
}

static void test_rng_deterministic(void)
{
    uint32_t seed_a = 12345;
    uint32_t seed_b = 12345;

    uint32_t value_a = nc_xorshift32(&seed_a);
    uint32_t value_b = nc_xorshift32(&seed_b);

    assert(value_a == value_b);
}

static void test_different_rng_steps(void)
{
    uint32_t state = 12345;

    uint32_t first = nc_xorshift32(&state);
    uint32_t second = nc_xorshift32(&state);

    assert(first != second);
}

int main(void)
{
    test_manhattan_distance();
    test_rng_deterministic();
    test_different_rng_steps();

    printf("All neon_core tests passed!\n");

    return 0;
}