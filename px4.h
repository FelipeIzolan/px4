#include <stdint.h>

#ifndef PX4H
#define PX4H

typedef struct {
  uint8_t width;
  uint8_t height;
  uint8_t * data;
} px4;

px4 * px4_decode(FILE * file);
void * px4_encode(px4 * ctx, char * filename);

uint8_t px4_pack(uint8_t hi, uint8_t lo);
uint8_t px4_unpack_hi(uint8_t packed);
uint8_t px4_unpack_lo(uint8_t packed);

uint8_t px4_get(px4 * ctx, uint8_t x, uint8_t y);
uint8_t px4_set(px4 * ctx, uint8_t x, uint8_t y, uint8_t col); 

#endif // PX4H
