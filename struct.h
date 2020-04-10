#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stddef.h>

typedef struct dict {
	struct node *array;
	size_t length;
	size_t capacity;
} Dict;

typedef struct node {
	char nodeChar;
	struct node *prefix;
	struct node **children;
} Node;

void dictInit(Dict *d);

void dictPrint(Dict *d);

#endif
