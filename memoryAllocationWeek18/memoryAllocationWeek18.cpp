#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;


result *results[100];


int numResults = 0;


int readFile(char *fileName);


void initialiseResults();


void printResult(result *aResult);

int main()
{
	char fileName[] = "C:\\Users\\sndri\\Documents\\Visual Studio 2015\\Projects\\memoryAllocationWeek18\\memoryAllocationWeek18\\results.txt";
	int i = 0;


	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}

	while (results[i] != NULL)
	{
		printResult(results[i]);
		i++;
	}

	return 0;
}

void printResult(result *aResult)
{
	printf("%d\t%s\t%s\t%c\t%c\t%c\t%c\n", aResult->id, aResult->firstName, aResult->lastName, aResult->english,aResult->maths,aResult->french,aResult->philosophy);
}

void initialiseResults()
{
	int i;
	for (i = 0; i < 101; i++)
	{
		results[i] = NULL;
	}
}

int readFile(char *fileName)
{
	FILE *ptr;
	int i = 0;
	char delim[5] = "\t";
	char line[200];
	char *token;
	ptr = fopen(fileName, "r");
	if (ptr == NULL) return 0;

	do
	{
		fgets(line, 199, ptr);
		if (strstr(line, "1"))
		{
			results[numResults] = (result *)malloc(sizeof(result));

			token = strtok(line, delim);
			results[numResults]->id = atol(token);

			strcpy(results[numResults]->firstName, strtok(NULL, delim));
			strcpy(results[numResults]->lastName, strtok(NULL, delim));

			token = strtok(NULL, delim);
			results[numResults]->english = *token;
			
			token = strtok(NULL, delim);
			results[numResults]->maths = *token;

			token = strtok(NULL, delim);
			results[numResults]->french = *token;

			token = strtok(NULL, delim);
			results[numResults]->philosophy = *token;

			numResults++;
		}
	} while (!feof(ptr));



	return 1;
}
