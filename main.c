#include <stdio.h>

int main(int agrc, char * argv)
{
	FILE * abcd = fopen("abcd.txt", "rw");
	if (!abcd) {
		printf("Failed\n");
	}
	else {
		fclose(abcd);
	}
}
