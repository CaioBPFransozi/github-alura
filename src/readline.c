#ifndef READLINE_GUARD
#define READLINE_GUARD

#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#endif

char *readline() {
	char *result = NULL;
	size_t size = 0;

	if (getline(&result, &size, stdin) == -1) {
		printf("Impossível ler string");
		exit(-4);
	};

	return result;
}
