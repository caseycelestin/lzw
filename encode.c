#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode(char *argv[])
{
	Node dictionary;
	dictInit(&dictionary);

	FILE *file = fopen(argv[1], "r");
	
	int prefixChar = fgetc(file);
	Node *prefixNode = &dictionary.children[prefixChar];

	int nextChar;
	while((nextChar = fgetc(file)) != EOF)
	{
		Node *nextNode = isChild(prefixNode, nextChar);
		if(nextNode != 0)
			prefixNode = nextNode;
		else
		{
			printf("%i\n", (int)prefixNode);
			addChild(prefixNode, nextChar);
			prefixNode = &dictionary.children[nextChar];
		}	
	}

	printf("%d\n", (int)prefixNode);

	dictPrint(&dictionary);

/*
	Node *test = &dictionary.children[120];
	addChild(test, '%');

	if(isChild(test, '%')) printf("YES!!\n");
	if(isChild(test, 'r')) printf("NO!!\n");
*/

	dictFree(&dictionary);
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode(argv);
	

	//printNodes(&dictionary);	

}

