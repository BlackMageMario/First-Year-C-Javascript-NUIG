// Lab Examination 12th April.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int year;
	double price[12];
	double average;
}oil;


int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int choice = 0;
	float highestOilPrice = 0;
	char *months[12]{ "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	char *month = "January";
	int yearVariable = 0;
	char buffer[100] = "a";
	char inputBuffer[3] = "a";
	char deLim[2] = "\t";
	char * token;
	oil oilStructures[100];
	FILE *filePointer;
	char fileName[] = "oil.txt";
	if ((filePointer = fopen(fileName, "r")) == NULL)
	{
		perror("Error: ");
	}
	else
	{
		for (j = 0; j < 4; j++)
		{
			fgets(buffer, 100, filePointer);
		}
		j = 0;
		while(fgets(buffer, 100, filePointer))
		{
			if (ferror(filePointer))
			{
				break;
			}
			if((token = strtok(buffer, deLim)) != 0)oilStructures[j].year = atoi(token);
			if((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[0] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[1] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[2] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[3] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[4] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[5] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[6] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[7] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[8] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[9] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[10] = atof(token);
			if ((token = strtok(NULL, deLim)) != 0)oilStructures[j].price[11] = atof(token);
			oilStructures[j].average = 0;
			for (k = 0; k < 12; k++)
			{
				oilStructures[j].average = oilStructures[j].average + oilStructures[j].price[k];
			}
			oilStructures[j].average = (oilStructures[j].average) / 12;
			j++;
		}
		do
		{
			printf("Enter your choice:\n0 - quit\n1 - find the month with the highest price.\n2 - find the year with the highest average price.\n");
			fgets(inputBuffer, 3, stdin);
			sscanf(inputBuffer, "%s", inputBuffer);
			choice = atoi(inputBuffer);
			if (choice == 0)
			{
				printf("Terminating program...\n");
				break;
			}
			else if (choice == 1)
			{
				highestOilPrice = 0;
				for (i = 0; i < j; i++)
				{
					for (k = 0; k < 12; k++)
					{
						if (oilStructures[i].price[k] > highestOilPrice)
						{
							highestOilPrice = oilStructures[i].price[k];
							yearVariable = oilStructures[i].year;
							month = *(months + k);
						}
					}
				}
				printf("Highest Price Month was %s with %f in %d\n", month, highestOilPrice, yearVariable);
			}
			else if (choice == 2)
			{
				highestOilPrice = 0;
				for (i = 0; i < j; i++)
				{
					if (oilStructures[i].average > highestOilPrice)
					{
						highestOilPrice = oilStructures[i].average;
						yearVariable = oilStructures[i].year;
					}
				}
				printf("Highest Annual Average Price was %f in %d\n", highestOilPrice, yearVariable);
			}
			else
			{
				printf("Error, incorrect input! Returning to start of program!\n");
			}
			/*switch (choice)
			{
			case 0:
				printf("Terminating program...\n");
				break;
			case 1:
				highestOilPrice = 0;
				for (i = 0; i < j; i++)
				{
					for (k = 0; k < j - 1; k++)
					{
						if (oilStructures[i].price[k] > highestOilPrice)
						{
							highestOilPrice = oilStructures[i].price[k];
							yearVariable = oilStructures[i].year;
							month = *(months + k);
						}
					}
				}
				printf("Highest Price Month was %s with %f in %d\n", month, highestOilPrice, yearVariable);
				break;
			case 2:
				highestOilPrice = 0;
				for (i = 0; i < j; i++)
				{
					if (oilStructures[i].average > highestOilPrice)
					{
						highestOilPrice = oilStructures[i].average;
						yearVariable = oilStructures[i].year;
					}
				}
				printf("Highest Annual Average Price was %f in %d\n", highestOilPrice, yearVariable);
				break;
			default:
				printf("Error, incorrect input! Returning to start of program!\n");
			}*/ //here is a switch method that I also wrote
			// (not so) funny story; I was confused to as why my program was crashing
			// I thought it was my switch statement. I thought it was my way of getting input.
			// no, it was because I got confused over how you use enums.
			// so I fixed it. Only took half an hour.
		} while (choice != 0);
	}
	return 0;
}