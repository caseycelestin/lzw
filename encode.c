#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode()
{
	Dict dictionary;
	dictInit(&dictionary);
	dictPrint(&dictionary);
	
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode();
	

	//printNodes(&dictionary);	

}

void printNodes(struct node **d)
{
	for(int i = 0; i < 128; i++)
	{
		struct node curr = (*d)[i];
		printf("Char: %c\n", curr.nodeChar);
	}
}
