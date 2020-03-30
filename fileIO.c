#include <stdio.h>

#include "fileIO.h"

void openOriginal(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "r");

	char c = fgetc(fp);

	while (c != EOF)
	{
  	printf("%c", c);
		c = fgetc(fp);
	}
}
