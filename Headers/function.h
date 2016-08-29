#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_In 4
#define MAX_In 5

#define MIN_Char 3
#define MAX_Char 10

#define nBands (sizeof band/sizeof *band)

enum resistorBandColors {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GRAY, WHITE, UNKNOWN};
//unsigned int multiplier[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

/*	enum is restricted to integers and bytes 
enum resistorBandTolerance {SILVER = 0.1, GOLD = 0.05};
//Need a naming convention for:
//, BROWN = 0.01, RED = 0.02, GREEN = 0.005, BLUE = 0.025, VIOLET = 0.001

*/

typedef struct 
{
	char *name;
	enum resistorBandColors id;
} resistor;




int srchBands (char *ccode);

int scmp (char *a, char *b);
