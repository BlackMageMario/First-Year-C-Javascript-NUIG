// Week 22 Assignment
// Note to self: two demensional arrays are literally satan if you don't give them memory space.

#include "stdafx.h"
#include <string.h>

void sortString(int numStrings, char *strings[]);
void writeToFile(int numStrings, char *fileName, char *strings[]);


int main( int argc, char *argv[] )
{
	int i = 0;
	if (argc > 22)
	{
		//why would you overload this? :c
		printf("Function overloaded!");
		return 0;
	}
	else
	{
		sortString(argc, argv);
		writeToFile(argc, argv[1], argv);
	}
    return 0;
}

void sortString(int numStrings, char *string[])
{
	//sorts argv and the values in it; returns these values.
	int i = 0;
	int j = 0;
	char *dummy = "nope";
	//populate newArray
	printf("Printing unsorted array:\n");
	for (i = 2; i < numStrings; i++)
	{
		printf("%s\n", string[i]);
	}
	// you don't need a second array for this but I thought it looked better and was easier to understand
	for (i = 2; i < numStrings; i++)
	{
		for (j = 2; j < numStrings - 1; j++)
		{
			if (strcmp(string[i], string[j]) < 0)
			{
				//swaps them based on whether one is higher than the other;
				dummy = string[j];
				string[j] = string[i];
				string[i] = dummy;
			}
		}
	}
	printf("Printing sorted array:\n");
	//prints the sorted array;
	for (i = 2; i < numStrings; i++)
	{
		printf("%s\n", string[i]);
	}
}

void writeToFile(int numStrings, char *fileName, char *strings[])
{
	//prints to file.
	int i = 0;
	FILE *filePointer;
	if (NULL == (filePointer = fopen(fileName, "w")))
	{
		//checks for errors
		perror("Error!");
	}
	else
	{
		for (i = 2; i < numStrings; i++)
		{
			fprintf(filePointer, "%s\n", strings[i]);
		}
	}
	fclose(filePointer);
}