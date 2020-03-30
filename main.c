#include <stdio.h>
#include <stdlib.h>

#include "fileIO.h"

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	openOriginal(&fp, argc, argv);
		rewind(fp);
		char c = fgetc(fp);

		while (c != EOF)
		{
  		printf("%c", c);
			c = fgetc(fp);
		}
	char *dictionary = malloc(128 * sizeof(char));
	for(int i = 0; i < 128; i++)
		dictionary[i] = i;

	for(int i = 0; i < 128; i++)
		printf("%c\n", dictionary[i]);

	fclose(fp);
	free(dictionary);
}
