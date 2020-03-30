#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "fileIO.h"

int openOriginal(FILE **fp, int argc, char *argv[])
{
	*fp = fopen(argv[1], "r");

	if(*fp == NULL)
	{
		fprintf(stderr, "%s in %s %s:%d\n", strerror(errno), __func__, __FILE__, __LINE__);
		fclose(*fp);
		return -1;
	} else {
		
		char c = fgetc(*fp);

		while (c != EOF)
		{
  		printf("%c", c);
			c = fgetc(*fp);
		}
	}	
	return 1;
}
