#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode()
{
	Node dictionary;
	dictInit(&dictionary);
/*
	char prefixChar = fgetc(file);
	Node prefixNode = dictionary.children[prefixChar];

	while((char nextChar == fgetc(file)) != EOF)
	{
		
	}
	*/

	Node *test = &dictionary.children[120];
	addChild(test, '%');

	dictPrint(&dictionary);

	if(isChild(test, '%')) printf("YES!!\n");
	if(isChild(test, 'r')) printf("NO!!\n");


	dictFree(&dictionary);
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode();
	

	//printNodes(&dictionary);	

}

