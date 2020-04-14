#include "struct.h"

#include <stdlib.h>
#include <stdio.h>

void dictInit(Node *d)
{	
	d->children = malloc(128 * sizeof(Node));
	for(int i = 0; i < 128; i++)
	{
		Node newNode;
		newNode.nodeChar = i;
		newNode.length = 0;
		newNode.capacity = 0;
		(d->children)[i] = newNode;
	}
	d->length = 128;
	d->capacity = 128;
}

void addChild(Node *p, char c)
{

}

void dictPrint(Node *d)
{
	for(int i = 0; i < d->length; i++)
	{
		Node child = d->children[i];
		char out = child.nodeChar;
		
		for(int j = 0; j < child.length; j++)
		{
			dictPrint(&(child.children[j]));
		}
		printf("%c\n", out);
	}
}

void printHelp(char *p, Node *c)
{

}
