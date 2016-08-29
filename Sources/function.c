#ifndef FUNCTION_H
#define FUNCTION_H 
#include "function.h"

resistor band[] = {
	{"black", BLACK},
	{"brown", BROWN},
	{"red", RED},
	{"orange", ORANGE},
	{"yellow", YELLOW},
	{"green", GREEN},
	{"blue", BLUE},
	{"violet", VIOLET},
	{"gray", GRAY},
	{"white", WHITE}
};

int srchBands (char *ccode)
{
	char lccode [MAX_Char];
	strcpy(lccode, ccode);
	for (int i = 0; i < (int)nBands; ++i)
	{
		if (*lccode == *(band[i].name))
		{
			if (!scmp(band[i].name, lccode))
			{
				return i;
			}
		}
	}
	return -1;
}

int scmp (char *a, char *b)
{
    if (!a && !b) return 0;
    if ( a && !b) return 1;
    if (!a &&  b) return -1;

    for (; *a && *b && *a == *b; a++, b++) {}

    return *a - *b;
}

#endif

