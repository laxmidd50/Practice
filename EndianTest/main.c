#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char storage[4];
	memset(storage, 0xAA, 4);
	(int)(*storage) = 0x01234567;
	if (storage[0] == 0x01)
		printf("Big endian\n");
	else
		printf("Little endian\n");
	int i;
	for (i = 0; i < 10; i++)
		printf("%02x ", (char)storage[i]);
	printf("\n");
	return 0;
}
