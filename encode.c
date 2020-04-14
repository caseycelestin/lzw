#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode(char *argv[])
{
	Node dictionary;
	dictInit(&dictionary);

	unsigned int code = 128;

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
			printf("<%u>", prefixNode->code);
			addChild(prefixNode, nextChar, code++);
			prefixNode = &dictionary.children[nextChar];
		}	
	}
	printf("<%u>\n", prefixNode->code);

	//dictPrint(&dictionary);

	dictFree(&dictionary);
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode(argv);
	

	//printNodes(&dictionary);	

}

