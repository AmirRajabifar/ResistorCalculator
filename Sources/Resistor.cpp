#include "Resistor.h"

items band_list[] = {
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



void Resistor::setBands (const std::string& band1, const std::string& band2, const std::string& band3)
{
	// arbitory value
	this->__band1 = srchItems(band1);
	this->__band2 = srchItems(band2);
	this->__band3 = srchItems(band3);
}






int Resistor::srchItems (const std::string& ccode)
{
	char lccode [MAXCC] = "";
	//strcpy2lower (lccode, ccode); // converts everything to lower case
	for (int i = 0; i < (int)nItems; ++i) 
		if (*lccode == *(band_list[i].name))
			if (!this->scmp(band_list[i].name, lccode))
				return i;
	return -1;
}

int Resistor::scmp (char const *a, char const *b)
{
    if (!a && !b) return 0;
    if ( a && !b) return 1;
    if (!a &&  b) return -1;

    for (; *a && *b && *a == *b; a++, b++) {}

    return *a - *b;
}

/*

char Resistor::strcpy2lower (char *dest, char *src)
{
    if (!src || !dest) return NULL;
    char *d = dest;
    for (; *src; src++, d++)
        if ('A' <= *src && *src <= 'Z')
            *d = *src | (1 << 5);
        else
            *d = *src;
    *d = 0;
    return dest;
}

*/
