// Week 16 Assignment by Eamonn Hannon on 2nd Feburary 2016
// Loops through several names and emails, using delimiters and tokens.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	int month;
	int year;
}date;

typedef struct
{
	char firstName[50];
	char lastName[50];
	char email[50];
	date dob;
}person;

void printOutInfo(person people[]);

int main()
{
	int i = 0;
	FILE *filePointer;
	char *stringToken;
	const char deLim[3] = ",/"; // the delimiter
	person people[4];
	char buffer[200];
	filePointer = fopen("people.txt", "r");
	if (NULL == filePointer)
	{
		perror("Error!");
		return 0;
	}
	else
	{
		fgets(buffer, 200, filePointer);
		while (!feof(filePointer)) //loops through until the end of the file.
		{
			fgets(buffer, 200, filePointer); //creates a string of all the data, then goes through and uses string tokens to seperate the information.
			stringToken = strtok(buffer, deLim);
			strcpy(people[i].firstName, stringToken);
			stringToken = strtok(NULL, deLim);
			strcpy(people[i].lastName, stringToken);
			stringToken = strtok(NULL, deLim);
			strcpy(people[i].email, stringToken);
			stringToken = strtok(NULL, deLim);
			people[i].dob.day = atoi(stringToken);
			stringToken = strtok(NULL, deLim);
			people[i].dob.month = atoi(stringToken);
			stringToken = strtok(NULL, deLim);
			people[i].dob.year = atoi(stringToken);
			i++;
		}
		printOutInfo(people);
		fclose(filePointer);
	}
	return 0;
}

void printOutInfo(person people[])
{
	// prints out all the necessary information, as well as calculates the date of birth and the age of the person.
	int i = 0;
	int age = 0;
	char month[20] = "";
	for (i = 0; i < 4; i++)
	{
		printf("First Name: %s\n", people[i].firstName);
		printf("Last Name: %s\n", people[i].lastName);
		printf("Email: %s\n", people[i].email);
		switch (people[i].dob.month) {
			case 1:
				strcpy(month, "January");
				break;
			case 2:
				strcpy(month, "Feburary");
				break;
			case 3:
				strcpy(month, "March");
				break;
			case 4:
				strcpy(month, "April");
				break;
			case 5:
				strcpy(month, "May");
				break;
			case 6:
				strcpy(month, "June");
				break;
			case 7:
				strcpy(month, "July");
				break;
			case 8:
				strcpy(month, "August");
				break;
			case 9:
				strcpy(month, "September");
				break;
			case 10:
				strcpy(month, "October");
				break;
			case 11:
				strcpy(month, "November");
				break;
			case 12:
				strcpy(month, "December");
				break;
			default:
				strcpy(month, "Error!");
				break;

		}//switch statement to find the correct date.
		printf("DOB: %s %d, %d\n", month, people[i].dob.day, people[i].dob.year);
		age = 2016 - people[i].dob.year;
		printf("Age: %d\n\n", age);
	}
}