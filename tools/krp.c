#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <stdint.h>

int main(int argc, char **argv) {
	if (argc<3) {
		printf("Usage: %s <out> <files> ...\n", argv[0]);
		return 1;
	}
	FILE *in, *out = fopen(argv[1], "w");
	if (!out) {
		perror("Error: Output file is invalid! Error");
		return 127;
	}
	fprintf(out, "KRPK");
	unsigned char *data = malloc(1);
	unsigned char *cdata;
	size_t size;
	int csize;
	for (int i=2; i<argc; i++) {
		in = fopen(argv[i], "r");
		if (!!strcmp(argv[i], "build/assets.krp")) {
			printf("Processing asset %d (\"%s\")\n", i-1, argv[i]);
			if (!in) {
				perror("Input file is invalid");
				return 127;
			}
			fseek(in, 0, SEEK_END);
			size = ftell(in);
			data = realloc(data, size);
			fseek(in, 0, SEEK_SET);
			printf("Size of asset %d: %lu\n", i-1, fread(data, 1, size, in));
			cdata = CompressData(data, size, &csize);
			printf("Writing data buffer...\n");
			fwrite(&csize, sizeof(int), 1, out);
			fwrite(cdata, 1, csize, out);
			free(cdata);
		}
	}
	printf("Done!\n");
}
