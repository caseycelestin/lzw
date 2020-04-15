#include "struct.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void dictInit(Node *d)
{
	d->nodeChar = 'C';
	d->children = malloc(128 * sizeof(Node));
	for(int i = 0; i < 128; i++)
	{
		Node newChild;
		nodeInit(&newChild, i, i);
		(d->children)[i] = newChild;
	}
	d->length = 128;
	d->capacity = 128;
}

void nodeInit(Node *n, char c, uint16_t i)
{
	n->nodeChar = c;
	n->length = 0;
	n->capacity = 0;
	n->children = 0;
	n->code = i;
}

void dictFree(Node *d)
{
	for(int i = 0; i < d->length; i++)
	{
		dictFree(&d->children[i]);
	}
	free(d->children);
}

Node *isChild(Node *n, char c)
{
	for(int i = 0; i < n->length; i++)
	{
		Node *child = &n->children[i];
		if(c == child->nodeChar) return child;
	}

	return 0;
}

void addChild(Node *p, char c, uint16_t i)
{
	if(p->length == p->capacity)
	{
		if(p->capacity == 0) p->capacity = 1;
		int newCapacity = p->capacity * 2;
		if(newCapacity > p->capacity && newCapacity < SIZE_T_MAX / sizeof(Node))
		{
			Node *newArray = realloc(p->children, newCapacity * sizeof(Node));
			if(newArray != 0)
			{
				p->children = newArray;
				p->capacity = newCapacity;
			}
			else 
				printf("OUT OF MEMORY\n"); // Out of Memory
		}
		else
			printf("OVERFLOW ERROR\n"); // Overflow error
	}

	Node newChild;
	nodeInit(&newChild, c, i);
	(p->children)[p->length] = newChild;
	p->length++;	
}

void dictPrint(Node *d)
{
	char out = d->nodeChar;
	printf("%c\n", out);	
	for(int i = 0; i < d->length; i++)
	{
		Node child = d->children[i];		
		printHelp(&child, 0);
	}	
}

void printHelp(Node *n, int t)
{
	for(int j = 0; j < t; j++) printf(" ");
	char out = n->nodeChar;
	printf("%c\n", out);	
	for(int i = 0; i < n->length; i++)
	{
		Node child = n->children[i];		
		printHelp(&child, t + 1);
	}	


}
