#include "struct.h"

#include <stdlib.h>
#include <stdio.h>

void dictInit(Dict *d)
{	
	d->array = malloc(128 * sizeof(Node));
	for(int i = 0; i < 128; i++)
	{
		Node newNode;
		newNode.nodeChar = i;
		newNode.children = 0;
		newNode.prefix = 0;
		(d->array)[i] = newNode;
	}
	d->length = 128;
	d->capacity = 128;
}

void dictPrint(Dict *d)
{
	for(int i = 0; i < d->length; i++)
	{
		char out = ((d->array)[i]).nodeChar;
		printf("%c\n", out);
	}
}


