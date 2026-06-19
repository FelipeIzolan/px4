#include <stdint.h>

#ifndef PX4H
#define PX4H

typedef struct {
  uint8_t width;
  uint8_t height;
  uint8_t * data;
} px4;

uint8_t px4_pack(uint8_t hi, uint8_t lo);
uint8_t px4_unpack_hi(uint8_t packed);
uint8_t px4_unpack_lo(uint8_t packed);

uint8_t px4_get(const px4 * ctx, uint8_t x, uint8_t y);
uint8_t px4_set(px4 * ctx, uint8_t x, uint8_t y, uint8_t col); 

px4 * px4_decode(const char * filename);
uint8_t px4_encode(const px4 * ctx, const char * filename);
void px4_free(px4 * ctx);

#endif // PX4H
