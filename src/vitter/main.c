#include "vitter.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum {
	VITTER_COMPRESS,
	VITTER_DECOMPRESS,
	VITTER_UNSPECIFIED,
} vitter_operation;

static vitter_operation parse_arguments(vitter_t *v, int argc, char *argv[]);
static void parse_buffer_size(uint64_t *buffer_size);

int main(int argc, char *argv[])
{
	vitter_t v;
	vitter_operation op = parse_arguments(&v, argc, argv);
	if (!vitter_alloc(&v, 257))
		return free(v.stream.base), EXIT_FAILURE;
	switch (op) {
	case VITTER_COMPRESS:
		for (;;) {
			int c = getchar();
			if (c < 0)
				break;
			vitter_encode(&v, (uint16_t)c);
		}
		vitter_encode(&v, 256);
		bitstream_flush(&v.stream);
		break;
	case VITTER_DECOMPRESS:
		for (;;) {
			uint16_t c;
			if (!vitter_decode(&c, &v))
				vitter_dealloc(&v), free(v.stream.base), exit(2);
			if (c >> 8)
				break;
			putchar(c);
		}
		break;
	case VITTER_UNSPECIFIED:
		fputs("operation unspecified\n", stderr);
		break;
	}
	vitter_dealloc(&v);
	free(v.stream.base);
	return 0;
}

static vitter_operation parse_arguments(vitter_t *v, int argc, char *argv[])
{
	struct option lopts[] = {
		{ "buffer-size", required_argument, NULL, 'b', },
		{ "compress", no_argument, NULL, 'c', },
		{ "decompress", no_argument, NULL, 'd', },
		{ NULL, no_argument, NULL, 0, },
	};
	int index = 0, compress = 0, decompress = 0;
	uint64_t buffer_size = 65536;
	for (;;) {
		int c = getopt_long(argc, argv, "b:cdh", lopts, &index);
		if (c < 0)
			break;
		else if (c == 'b')
			parse_buffer_size(&buffer_size);
		else if (c == 'c')
			compress = 1;
		else if (c == 'd')
			decompress = 1;
	}
	if (compress && decompress)
		fprintf(stderr, "both %s and %s are specified simultaneously\n",
			lopts[1].name, lopts[2].name), exit(3);
	void *buffer = malloc(buffer_size);
	if (!buffer)
		perror("malloc"), exit(4);
	bitstream_init(&v->stream, buffer, buffer_size);
	return compress ? VITTER_COMPRESS :
		(decompress ? VITTER_DECOMPRESS : VITTER_UNSPECIFIED);
}

static void parse_buffer_size(uint64_t *buffer_size)
{
	char *ep;
	*buffer_size = strtoul(optarg, &ep, 10);
	if (errno == ERANGE)
		perror("strtoul"), exit(5);
	switch (*ep) {
	case '\0':
		break;
	case 'k':
	case 'K':
		*buffer_size <<= 10;
		break;
	case 'm':
	case 'M':
		*buffer_size <<= 20;
		break;
	case 'g':
	case 'G':
		*buffer_size <<= 30;
		break;
	default:
		fprintf(stderr, "invalid buffer size, %s", optarg), exit(6);
	}
}
