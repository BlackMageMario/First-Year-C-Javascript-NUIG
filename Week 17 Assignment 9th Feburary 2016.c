// Week 17 Programming Assignment Solution by Eamonn Hannon, 9th Feburary 2016
// Reads results from file, allocates memory dynamically to each result, prints them out, then frees the memory up.
// Ironically the main issue I had was with string tokens which were not required to use in thsi program.

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include <string.h>

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;

// array of pointers to 'result' structures - assuming that there is 100 or less records in the data file
result *results[100];

// number of records read from the file
int numResults = 0;

// read file and populate the results
// you will need to use malloc to allocate a new 'result' structure for each record read from the file
// the *result pointer returned by malloc will be stored in the next member of the array *results[]
int readFile(char *fileName);

// set all the pointers in *results[] to NULL before reading in the file
void initialiseResults();

// function to print an individual member of the *results[] array
void printResult(result *aResult);

int main()
{
	char fileName[] = "results.txt";
	int i = 0;


	void initialiseResults();

	readFile(fileName);
	printf(" ID\tFirst Name\tLast Name\tEnglish\tFrench\tMaths\tPhilosophy\n");
	printf("----------------------------------------------------------------------------\n");
	while (i < (numResults - 1))
	{
		printResult(results[i]);
		i++;
	}
	// Frees up space for later use.
	for (i = 0; i < 100; i++)
	{
		free(results[i]);
		results[i] = NULL;
	}
	return 0;
}

void printResult(result *aResult) // prints out an individual result.
{
	printf("%d\t %-10s\t %-10s\t %c\t %c\t %c\t %c\t\n", aResult->id, aResult->firstName, aResult->lastName,
		aResult->english, aResult->french, aResult->maths, aResult->philosophy);
}

void initialiseResults()
{//ensures all of results[i] = NULL before the program begins.
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		results[i] = NULL;
	}
}

int readFile(char *fileName) {
	int i = 0;
	FILE *filePointer;
	char temp[100];
	filePointer = fopen(fileName, "r"); // the following if fopen actually opened the file; if so, it continues.
	if (NULL == filePointer)
	{
		perror("Error:");
	}
	else
	{
		fgets(temp, 200, filePointer);//skips the first line.
		while (!feof(filePointer))
		{
			results[i] = (result *)malloc(sizeof(result)); //allocates the memory before each result.
			fscanf(filePointer, "%d\t%s\t%s\t%c\t%c\t%c\t\t%c", &results[i]->id, &results[i]->firstName, &results[i]->lastName,
				&results[i]->english, &results[i]->french, &results[i]->maths, &results[i]->philosophy);
			// I tried to use delimiters and string functions but I couldn't get strcpy to work or assign the value
			// of a token to a character (like english). I should probably practise this.
			numResults++; // this is an important counter - used to help ensure that the program prints out the results correctly.
			i++;
		}
	}

	return 1;
}