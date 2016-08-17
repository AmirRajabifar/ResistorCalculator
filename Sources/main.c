#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

#define nItems (sizeof item_list/sizeof *item_list)

char status = 'Y'; 
//
enum {MINC = 3, MAXCC = 10};
// resister bands
enum resistor_band_items {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN,
								 BLUE, VIOLET, GRAY, WHITE, UNKNOWN};
struct items
 {
 	char *name;
 	enum resistor_band_items id;
 } item_list[] = {
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
unsigned int multiplier[] = {1, 10, 100, 1000, 10000, 100000, 1000000,
	 10000000, 100000000, 1000000000};

int srchItems (char *ccode); //a search for index values
char *strcpy2lower (char *dest, char *src); //converts to lower case
int scmp (char *a, char *b); //simple string comarison
char *sepnumber (char *s, long val); //puts space every 3rd digit
char *sepDoublenumber (char *s, double val);
void cutAtChar (char* str, char c);

int main(void)
{
	int i, error = 0, mult;
	char input[MINC][MAXCC]; //user input
	char invalid[MINC][MAXCC]; // invalid enteries
	int colour_val[MINC]; //stores the band value
	long total_resistance = 0; 
	char resistor_value_string[30] = "";//formatted output
	char *ptr;
	do
	{
	//prompt user 
	printf("%s\n%s\n%s\n",
		"Enter the colours of the resistor's three bands,",
		"beginning with the band nearest to the end.",
		"Type the coloues in lowercase letters only, NO CAPS.");

	for (i = 0; i < MINC; ++i)
	{
		printf("Band %d => ", i + 1); // print headers for each band
		scanf(" %s", &input[i]);  // get the user input
		// converts user input to index of colours
		colour_val[i] = srchItems(input[i]); 
	}
	int j = 0;		
	for (i = 0; i < MINC; ++i)
	{
		if (colour_val[i] == -1)
		{
			strcpy(invalid[j], input[i]);
			error++;
			j++;
		}
	}
	if (error > 0)
	{
		if (error == 1)
		{
			printf("Invalid colour: %s\n", invalid[0]);
		}
		else if (error == 2)
		{
			printf("Invalid colours: %s, %s\n", invalid[0], invalid[1]);
		}
		else 
		{
			printf("Invalid colours: %s, %s, %s\n",
			 invalid[0], invalid[1], invalid[2]);
		}
	}
	else
	{
		//
		for (i = 0; i < MINC - 1; ++i)
		{
			total_resistance = (total_resistance * 10) + colour_val[i];
		}
		mult = colour_val[2];
		if (mult == 9)
		{	
			double total_resistance_double;
			total_resistance_double = total_resistance;
			total_resistance_double *= multiplier[mult];
			sepDoublenumber (resistor_value_string, total_resistance_double);
			printf("Resistance value: %s -Ohms\n", resistor_value_string);
		}
		else
		{
			total_resistance *= multiplier[mult];
			sepnumber (resistor_value_string, total_resistance);
			printf("Resistance value: %s -Ohms\n", resistor_value_string);			
		}
	}
	error = 0;
	total_resistance = 0;
	for (i = 0; i < MINC; ++i)
	{
		colour_val[i] = 0;
	}
	//ask user if they want to continue
	printf("Do you whant to decode another resistor?\n");
	scanf(" %c", &status);
	if (status == 'Y');
	else break;
	} while (status == 'Y');
	return 0;
}

int srchItems (char *ccode)
{
	int i;
	char lccode [MAXCC] = "";
	strcpy2lower (lccode, ccode); // converts everything to lower case
	for (int i = 0; i < (int)nItems; ++i) 
		if (*lccode == *(item_list[i].name))
			if (!scmp(item_list[i].name, lccode))
				return i;
	return -1;
}

char *strcpy2lower (char *dest, char *src)
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

int scmp (char *a, char *b)
{
    if (!a && !b) return 0;
    if ( a && !b) return 1;
    if (!a &&  b) return -1;

    for (; *a && *b && *a == *b; a++, b++) {}

    return *a - *b;
}

/** separate long value every 3rd char into 's' */
char *sepnumber (char *s, long val)
{
    char numstr[3 * MAXCC] = "";
    char *p = numstr;
    size_t idx = 0, len = 0;

    sprintf (numstr, "%ld", val);
    for (; *p; p++) {}
    len = p - numstr;
//printf("%d\n", len);
    p = s + 3 * MAXCC - 2;

    while (len--) 
    {
        if (idx++ == 3) 
        {
            idx = 1;
            *p-- = ' ';
        }
        *p = numstr[len];
        if (len) p--;
    }
    for (idx = 0; *p; p++, idx++) s[idx] = *p; /* copy to s */
    s[idx] = *p;    /* nul-terminate */
    return s;
}

char *sepDoublenumber (char *string, double val)
{
    char numstr[3 * MAXCC] = "";
    char *p = numstr;
    char test[30];
    char *q = test;
    size_t idx = 0, len = 0;

    sprintf (numstr, "%lf", val);
    for (; *p; p++) {}
    len = p - numstr;
    p = string + 3 * MAXCC - 2;

    while (len--) 
    {
        *p = numstr[len];
        if (len) p--;
    }
    cutAtChar (p, '.');
    len = strlen(p);
    while (len--) 
    {
        if (idx++ == 3) 
        {
            idx = 1;
            *q-- = ' ';
        }
        
        *q = p[len];
        if (len) q--;
    }   
   	for (idx = 0; *q; q++, idx++) string[idx] = *q; /* copy to s */
	string[idx] = *q;    /* nul-terminate */  
    return string;
}

void cutAtChar (char* str, char c)
{
	if (!str) return; //validate parameter
	//find the char
	while (*str != '\0' && *str != c) str++;
	//make the location the end of the string
	*str = '\0';
}

