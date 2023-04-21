#include "hirolib.h"
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc<4) {
		SetColor16(COLOR_RED);
		SetMode(MODE_BOLD);
		printf("Usage: color <16/256> <fg> <bg>\n");
		ResetMode(MODE_BOLD);
		ResetColor();
		return 1;
	}
	if (atoi(argv[2]) == -1 || atoi(argv[3]) == -1) ResetColor16();
	else if (atoi(argv[1]) == 16) {
		SetColor16(atoi(argv[2]));
		SetBgColor16(atoi(argv[3]));
	} else if (atoi(argv[1]) == 256) {
		SetColor256(atoi(argv[2]));
		SetBgColor256(atoi(argv[3]));
	}
}
