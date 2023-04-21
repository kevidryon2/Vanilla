#include "raylib.h"
#include <stdlib.h>
#include <execinfo.h>
#include <unistd.h>
#include <signal.h>

#pragma once

void segfault() {
	void *stacktrace[64];
	backtrace(stacktrace, 64);
	printf("Vanilla crashed :(\tStacktrace: \n");
	for (int i=0; i<64; i+=4) {
		printf("%08x\t%08x\t%08x\t%08x\n", stacktrace[i], stacktrace[i+1], stacktrace[i+2], stacktrace[i+3]);
	}
  kill(getppid(), SIGTERM);
	exit(126);
}
