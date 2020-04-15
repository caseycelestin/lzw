#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stddef.h>
#include <stdint.h>

typedef struct node {
	char nodeChar;
	struct node *children;
	size_t length;
	size_t capacity;
	uint16_t code;
} Node;

void dictInit(Node *d);

void nodeInit(Node *n, char c, uint16_t i);

void dictFree(Node *d);

void addChild(Node *p, char c, uint16_t i);

Node *isChild(Node *n, char c);

void dictPrint(Node *d);

void printHelp(Node *n, int t);

#endif
