#include <stdio.h>
#include "IntPairs.h"

void IntPairs(int array[], int n, int x)
{
	// O(n^2)
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (array[i]+array[j] == x)
				printf("%i,%i\n", array[i], array[j]);
		}
	}
}
