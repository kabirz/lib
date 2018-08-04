#define _CRT_SECURE_NO_DEPRECATE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
void get_random_bytes(void *buf, size_t len)
{
	FILE *fp = NULL;

	if (buf == NULL || len == 0) {
		printf("invalid paremeters\n");
		exit(-1);
	}

	
	if ((fp=fopen("/dev/urandom", "r"))< 0) {
		printf("invalid paremeters\n");
		exit(-1);
	}

	if ((fread(buf, len, 1, fp)) <= 0) {
		printf("Can't get random bytes\n");
		fclose(fp);
		exit(-1);
	}
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	unsigned char buf[8] = { 0 };

	get_random_bytes(buf, sizeof(buf));

	for (size_t i = 0; i < ARRAY_SIZE(buf); i++) {
		printf("0x%0*x ", (int)sizeof(buf[i]) * 2, buf[i]);
	}
	printf("\n");

	return 0;
}
