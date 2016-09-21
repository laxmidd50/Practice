#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP_NUM 10

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Pass in file to count\n");
		return 0;
	}

	FILE *infile = fopen(argv[1], "rb");
	int array[256];
	int topchars[TOP_NUM];
	memset(topchars, -1, TOP_NUM);
	char tempchar;
	while (fread(&tempchar, 1, 1, infile))
	{
		array[tempchar]++;
	}
	fclose(infile);

	int i, j, k;
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < TOP_NUM; j++)
		{
			if (array[i] > array[topchars[j]])
			{
				for (k = TOP_NUM-2; k >= j; k--)
				{
					topchars[k+1] = topchars[k];
				}
				topchars[j] = i;
			}
		}
	}

	return 0;	
}
