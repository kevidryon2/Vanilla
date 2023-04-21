#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char hbuff[3] = "aa";
	while (!feof(stdin)) {
		fread(hbuff, 2, 1, stdin);
		printf("%c", (unsigned)strtol(hbuff, NULL, 16));
	}
}
