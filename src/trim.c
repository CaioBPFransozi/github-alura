#ifndef TRIM_GUARD
#define TRIM_GUARD

#include "trim.h"
#include <ctype.h>
#include <string.h>

#endif

char *trim(char *target) {
	while (isspace(*target)) target++;

	char *back = target + strlen(target);
	while (isspace(*--back));
	*(back + 1) = '\0';

	return target;
}
