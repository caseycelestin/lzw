#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stddef.h>

typedef struct node {
	char nodeChar;
	struct node *children;
	size_t length;
	size_t capacity;
} Node;

void dictInit(Node *d);

void addNode(Node *p, char c);

void dictPrint(Node *d);

void printHelp(char *p, Node *c);

#endif
