#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stddef.h>

typedef struct node {
	char nodeChar;
	struct node *children;
	size_t length;
	size_t capacity;
	unsigned int code;
} Node;

void dictInit(Node *d);

void nodeInit(Node *n, char c, unsigned int i);

void dictFree(Node *d);

void addChild(Node *p, char c, unsigned int i);

Node *isChild(Node *n, char c);

void dictPrint(Node *d);

void printHelp(Node *n, int t);

#endif
