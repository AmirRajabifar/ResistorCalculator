#include "function.h"

#define MINC 4
#define MAXC 5

int main(int argc, char const *argv[])
{
	//printf("%s\n", "Hello from new main");
	printf("%s:\t%d\n", "argc #",argc);

	for (int i = 1; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}

	return 0;
}