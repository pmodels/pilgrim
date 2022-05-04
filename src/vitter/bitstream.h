#ifndef __include_bitstream_h__
#define __include_bitstream_h__

#define PACKED __attribute__((packed))

#include <stdint.h>
#include <sys/types.h>

typedef struct _bitstream bitstream_t;

void bitstream_flush(bitstream_t *stream);
uint16_t bitstream_getbits(bitstream_t *stream, uint8_t length);
void bitstream_init(bitstream_t *stream, void *base, size_t size);
void bitstream_putbits(bitstream_t *stream, uint16_t bits, uint8_t length);

struct PACKED _bitstream {
	uint8_t *base;
	uint8_t bits : 5;
	uint32_t buffer : 24;
	uint64_t length : 35;
	uint8_t *pointer;
	uint64_t size;
};

#endif /* __include_bitstream_h__ */
