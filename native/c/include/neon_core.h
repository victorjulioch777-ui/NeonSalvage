#ifndef NEON_CORE_H
#define NEON_CORE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int x;
    int y;

} NC_Point;

/*
 *Generador pseudoalatorio xorshift32
 *
 * Modifica el estado y retorna el siguiente número.
 */
uint32_t nc_xorshift32(uint32_t *state);

/*
 *Calcula la distancia Manhattan entre dos puntos
 */
int nc_manhattan_distance(NC_Point a, NC_Point b);

#ifdef __cplusplus
}
#endif

#endif