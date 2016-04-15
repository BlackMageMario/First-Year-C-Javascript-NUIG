// Week 20 Assignment.cpp
// Just a very simple console application that uses argc and argv as arguments. The full argument list is *filename*,
// /l, /s, and /c

#include "stdafx.h"
#include <string.h>


int main( int argc, char *argv[] )
{
	FILE *fPointer;
	char buffer[200];//sets an arbritary size for the buffer.
	int numberOfLines = 0;
	int numberOfCharacters = 0;
	int size = 0;
	int i;
	if (argc > 5)
	{
		printf("Function Overloaded!");
	}
	else
	{//just checks that the file opened is a real file.
		if (NULL == (fPointer = fopen(argv[1], "r")))
		{
			perror("Error!");
		}
		else
		{// gets in file line by line. If the line is garbage, breaks out of the loop.;
			while (fgets(buffer, 200, fPointer))
			{
				
				if(ferror(fPointer))
				{
					break;
				}
				numberOfLines++;
				for (i = 0; i < 200; i++)
				{
					if (buffer[i] != '\n')
					{
						numberOfCharacters++;
					}
				}
				size = size + (sizeof(buffer));
			}
		}
	}
	for (i = 0; i < argc; i++)
	{// goes through the list of arguments and prints out the coresponding values. Uses strcmp to compare /l to argv[i], etc.
		/*printf("\narg[%d] = %s", i, argv[i]);*/
		if (strcmp("/l", argv[i]) == 0)
		{
			printf("Number of lines: %d lines.\n", numberOfLines);
		}
		else if (strcmp("/s", argv[i]) == 0)
		{
			printf("Size of the file: %d bytes.\n", size);
		}
		else if (strcmp("/c", argv[i]) == 0)
		{
			printf("Number of characters: %d characters.\n", numberOfCharacters);
		}
	}
	return 0;
}