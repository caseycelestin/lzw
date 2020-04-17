#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "entries.h"


void decode(char *argv[])
{
	DictArray decodeDict;
	arrayInit(&decodeDict);

	FILE *inFile = fopen(argv[1], "rb");

	uint16_t oldCode;
	uint16_t newCode;
	fread(&oldCode, sizeof(oldCode), 1, inFile);


	String s;
	stringInit(&s);
	stringCopy(&s, &decodeDict.dict[oldCode]);
	printf("%s", s.str);

	String c;
	stringInit(&c);
	stringPop(&c, &s);

	String add;
	stringInit(&add);
	stringCopy(&add, &s);

	while(fread(&newCode, sizeof(newCode), 1, inFile) == 1)
	{
		if(newCode >= decodeDict.length)
		{
			stringCopy(&s, &decodeDict.dict[oldCode]);
			stringCat(&s, &c);
		}
		else
		{	
			stringCopy(&s, &decodeDict.dict[newCode]);
		}
		printf("%s", s.str);
		stringPop(&c, &s);
		stringCopy(&add, &decodeDict.dict[oldCode]);
		stringCat(&add, &c);
		addEntry(&decodeDict, &add);
		oldCode = newCode;
	}

	free(s.str);
	free(c.str);
	free(add.str);
	arrayFree(&decodeDict);
	fclose(inFile);
}




int main(int argc, char *argv[])
{
	decode(argv);
}
