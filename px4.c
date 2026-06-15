#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "px4.h"

uint8_t px4_pack(uint8_t hi, uint8_t lo) {
  return (hi << 4) | (lo & 0x0F);
}

uint8_t px4_unpack_hi(uint8_t packed) {
  return (packed >> 4) & 0x0F;
}

uint8_t px4_unpack_lo(uint8_t packed) {
  return packed & 0x0F;
}

uint8_t px4_get(const px4 * ctx, uint8_t x, uint8_t y) {
  uint8_t index = (ctx->height * y + x) / 2;
  uint8_t byte = ctx->data[index];

  if (x % 2 == 0)
    return px4_unpack_hi(byte);

  return px4_unpack_lo(byte);
}

px4 * px4_decode(FILE * file) {
  px4 * p = malloc(sizeof(px4));

  if (file == NULL)
      return NULL;

  // identity
  if (fgetc(file) != 'P' || fgetc(file) != 'X' || fgetc(file) != '4')
      return NULL;

  p->width = fgetc(file);
  p->height = fgetc(file);

  uint16_t length = (p->width * p->height + 1) / 2;
  p->data = malloc(length);
  fread(p->data, sizeof(uint8_t), length, file);

  return p;
}
