// Week 21 Assignment
// Very simple program that takes variables entered in from the console, prints them out while doing simple calculations etc.
// I tried to enter in the address of *(argv+1) thinking that it would include argv[1] + argv[2] + argv[3] etc.
// into a va_list, but that does not appear to work. Again, I was over complicated things (and trying to be too cleaver :v)

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void inputFromConsole( int i, ... );

int main( int argc, char *argv[] )
{
	FILE *ptr;
	int i = 0;
	float max = 0;
	float theFloat = 0;
	char maxCity[30] = "";

	if ((ptr = fopen("Mar 8 2016.txt", "w")) == NULL)
	{
		perror("Error: ");
	}
	else
	{
		for (i = 1; i < argc; i = i + 2)
		{
			printf("Value of argvs: %s %s\n", argv[i], argv[i + 1]);
			theFloat = atof(argv[i + 1]);
			fprintf(ptr, "City: %s\tTemperature: %f degrees Celcius.\n", argv[i], theFloat);
			if (theFloat > max)
			{
				max = theFloat;
				strcpy(maxCity, argv[i]);
			}
		}
		printf("\nThe city with the hottest temperature is %s with %f degrees Celcius.", maxCity, max);
		fprintf(ptr, "\nThe city with the hottest temperature is %s with %f degrees Celcius.", maxCity, max);

	}
	//inputFromConsole( argc, *(argv+1) );
	fclose(ptr);
	return 0;
}
	
	

/*void inputFromConsole( int i, ... )
{
	int j;
	va_list consoleList;
	va_start( consoleList, i );
	for (j = 0; j < i; j = j + 1)
	{
		char* s = va_arg( consoleList, char * ); // this works for one line, but since it can't see any address beyond
		// *(argv + 1), it crashes on the next loop.
		printf("%s\n", s);
	}
	va_end(consoleList);
}*/