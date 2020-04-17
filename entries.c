#include "entries.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void arrayInit(DictArray *d)
{
	d->dict	= malloc(128 * sizeof(String));

	for(int i = 0; i < 128; i++)
	{
		String newString;
		char *entry = malloc(2 * sizeof(char));
		entry[0] = i;
		entry[1] = '\0';
		newString.str = entry;
		newString.strLen = 2;
		(d->dict)[i] = newString;

	}
	d->length = 128;
	d->capacity = 128;

}

void arrayFree(DictArray *d)
{
	for(int i = 0; i < d->length; i++)
	{
		free(d->dict[i].str);
	}
	free(d->dict);
}

void addEntry(DictArray *d, const String *add)
{
	if(d->length == d->capacity)
	{
		if(d->capacity == 0) d->capacity = 1;
		int newCapacity = d->capacity * 2;
		if(newCapacity > d->capacity && newCapacity < SIZE_T_MAX / sizeof(String))
		{
			String *newArray = realloc(d->dict, newCapacity * sizeof(String));
			if(newArray != 0)
			{
				d->dict = newArray;
				d->capacity = newCapacity;
			}
			else 
				printf("OUT OF MEMORY\n"); // Out of Memory
		}
		else
			printf("OVERFLOW ERROR\n"); // Overflow error
	}
	String new;
	stringInit(&new);
	stringCopy(&new, add);
	d->dict[d->length++] = new;
}

void stringInit(String *s)
{
	s->str = 0;
	s->strLen = 0;
}

void stringCopy(String *d, const String *s)
{
	free(d->str);
	d->str = 0;
	d->str = realloc(d->str, s->strLen * sizeof(char));
	for(int i = 0; i < s->strLen; i++)
		d->str[i] = s->str[i];

	d->strLen = s->strLen;
}

void stringPop(String *d, const String *s)
{
	free(d->str);
	d->str = 0;
	d->str = realloc(d->str, 2 * sizeof(char));
	d->str[0] = s->str[0];
	d->str[1] = '\0';
	d->strLen = 2;

}

void stringCat(String *d, const String *s)
{
	d->str = realloc(d->str, (d->strLen + s->strLen - 1) * sizeof(char));
	for(int i = d->strLen; i < d->strLen + s->strLen; i++)
		d->str[i - 1] = s->str[i - d->strLen];
	d->strLen = d->strLen + s->strLen - 1;
}







