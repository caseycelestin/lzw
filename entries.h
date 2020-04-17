#ifndef __ENTRIES_H__
#define __ENTRIES_H__

#include <stdint.h>

typedef struct string {
	char *str;
	int strLen;
} String;

typedef struct dictArray {
	uint16_t length;
	uint16_t capacity;
	String *dict;
} DictArray;

void arrayInit(DictArray *d);

void arrayFree(DictArray *d);

void addEntry(DictArray *d, const String *add);

void stringInit(String *s);

void stringCopy(String *d, const String *s);

void stringPop(String *d, const String *s);

void stringCat(String *d, const String *s);



#endif
