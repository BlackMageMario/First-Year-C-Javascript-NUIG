// Week 18 Assignment
// reads in contacts from a data file and displays them using linked lists.

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include <stdlib.h>

struct employeeData{
	char userName[20];
	char firstName[20];
	char lastName[20];
	char displayName[20];
	char jobTitle[20];
	char department[30];
	char officeNumber[20];
	char officePhone[20];
	char mobilePhone[20];
	char fax[20];
	char address[20];
	char city[20];
	char state[20];
	char zip[20];
	char country[20];
	struct employeeData *nextEmployee;
}*first = NULL;

struct employeeData *current;// these global variables make the program simple and easy to use.
//I'm not sure if you need current though - I think you might only need one?
//counter is there to ensure the program doesn't crash when printing off the last file.
struct employeeData *latest;
int counter = 0;

void openFile();//opens file

int printEmployee(employeeData *pointer);//prints file;

int main()
{//really just calls the functions
	int printed = 0;
	openFile();
	printed = printEmployee(first);
	return 0;
}

void openFile()
{
	//defines the simple variables to ensure hte program runs.
	const char deLim[3] = ",";
	char *token;
	FILE *filePointer;
	char line[200];
	filePointer = fopen("contacts.txt", "r");
	if (NULL == filePointer)
	{//checks for errors in opening the file. Otherwise, starts assigning data to the structures.
		perror("Error!");
	}
	else
	{
		fgets(line, 200, filePointer);
		while (!feof(filePointer))
		{//wish there was a simple way to loop through string tokens to read in the data easier...
			current =(struct employeeData *)malloc(sizeof(struct employeeData));
			fgets(line, 200, filePointer);
			token = strtok(line, deLim);
			strcpy(current->userName, token);
			token = strtok(NULL, deLim);
			strcpy(current->firstName, token);
			token = strtok(NULL, deLim);
			strcpy(current->lastName, token);
			token = strtok(NULL, deLim);
			strcpy(current->displayName, token);
			token = strtok(NULL, deLim);
			strcpy(current->jobTitle, token);
			token = strtok(NULL, deLim);
			strcpy(current->department, token);
			token = strtok(NULL, deLim);
			strcpy(current->officeNumber, token);
			token = strtok(NULL, deLim);
			strcpy(current->officePhone, token);
			token = strtok(NULL, deLim);
			strcpy(current->mobilePhone, token);
			token = strtok(NULL, deLim);
			strcpy(current->fax, token);
			token = strtok(NULL, deLim);
			strcpy(current->address, token);
			token = strtok(NULL, deLim);
			strcpy(current->city, token);
			token = strtok(NULL, deLim);
			strcpy(current->state, token);
			token = strtok(NULL, deLim);
			strcpy(current->zip, token);
			token = strtok(NULL, deLim);
			strcpy(current->country, token);
			token = strtok(NULL, deLim);
			if (NULL == first)
			{
				first = current;
				latest = current;
			}
			else
			{
				latest->nextEmployee = current;
				latest = current;
			}
			counter++;
		}
	}
}

int printEmployee(employeeData *pointer)
{//just prints off the data.
	int i = 0;
	latest = pointer;
	for (i = 0; i < counter-2; i++)
	{
		printf("User Name: %s\nFirst Name: %s\nLast Name: %s\nDisplay Name: %s\nJob Title: %s\nDepartment: %s\nOffice Number: %s\nOffice Phone Number: %s\Mobile Phone Number: %s\nFax: %s\nAddress: %s\nCity: %s\nState: %s\nZip: %s\nCountry: %s\n", latest->userName, latest->firstName,
			latest->lastName, latest->displayName, latest->jobTitle, latest->department, latest->officeNumber,
			latest->officePhone, latest->mobilePhone, latest->fax, latest->address, latest->city, latest->state,
			latest->zip, latest->country);
		latest = latest->nextEmployee;
	}
	//finally, free up the memory space in the program.
	free(current);
	current = NULL;
	free(first);
	first = NULL;
	free(latest);
	latest = NULL;
	return 1;
}