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

px4 * px4_decode(const char * filename) {
  FILE * file = fopen(filename, "rb");
  
  if (file == NULL)
      return NULL;

  // identity
  if (fgetc(file) != 'P' || fgetc(file) != 'X' || fgetc(file) != '4')
      return NULL;

  px4 * ctx = malloc(sizeof(px4));

  // reads width, height & size.
  fread(ctx, 4, 1, file);
  // reads data.
  ctx->data = malloc(ctx->size);
  fread(ctx->data, sizeof(uint8_t), ctx->size, file);

  return ctx;
}

uint8_t px4_encode(const px4 * ctx, const char * filename) {
  FILE * file = fopen(filename, "wb");
  
  if (file == NULL)
    return 0;

  // identity
  fputc('P', file);
  fputc('X', file);
  fputc('4', file);
 
  // writes width, height & size.
  fwrite(ctx, 4, 1, file);
  // writes data.
  fwrite(ctx->data, sizeof(uint8_t), ctx->size, file);

  fflush(file);
  fclose(file);
  
  return 1;
}

void px4_free(px4 * ctx) {
  if (ctx) {
    if (ctx->data)
      free(ctx->data);
    free(ctx);
  }
}
