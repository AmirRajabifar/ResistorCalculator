
#include "function.h"


int main(int argc, char const *argv[])
{
	char input[MIN_Char][MAX_Char]; //user input
	char color_index[argc];

	printf("%s:\t%d\n", "argc #",argc);

	for (int i = 1; i < argc; ++i)
	{
		strcpy(input[i-1] , argv[i]); // make a coppy of input
		color_index[i] = srchBands(input[i-1]);
		printf("%s:\t%d\n", input[i-1],color_index[i]);
	}

	return 0;
}