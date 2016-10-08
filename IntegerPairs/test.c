#include <stdio.h>
#include <stdlib.h>
#include "IntPairs.h"

void UsageError(void)
{
	printf("IntPairs: Takes a list of n integers and prints out all pairs that sum to a given x\n");
	printf("Usage: ./IntPairs <n> <x> <int 1> <int 2> ... <int n>\n");
	exit(0);
}

int main(int argc, char * argv[])
{
	int i, n, x;
	if (argc < 4) 
		UsageError();
	if (sscanf(argv[1], "%i", &n) != 1)
		UsageError();
	if (argc-3 != n)
		UsageError();
	if (sscanf(argv[2], "%i", &x) != 1)
		UsageError();
	int array[n];
	for (i = 0; i < n; i++)
	{
		if(sscanf(argv[i+3], "%i", &array[i]) != 1)
			UsageError();
	}
	IntPairs(array, n, x);
}
