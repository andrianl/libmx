#include "libmx.h"

int mx_strlen(const char *str)
{
	register const char *s;

	for (s = str; *s; ++s)
		;
	return (s - str);
}
