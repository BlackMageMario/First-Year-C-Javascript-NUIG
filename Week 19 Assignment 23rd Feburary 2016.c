#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account
{
	char surname[20];
	char firstname[20];
	int ID;
	char english;
	char maths;
	char french;
	char philosphy;
	struct account *next;
};
int entries = 0;
struct account *first;
struct account *binary;

void printMenu();

void readOriginalFile();
void writeData();
void readData();
void findRecord(int recordNumber);


void  main(void)
{
	int id;

	readOriginalFile();
	writeData();
	readData();

	do
	{
		printf("Enter which ID you want. Enter 0 to close the program: ");
		scanf("%d", &id);
		findRecord(id);
	} while (id != 0);

}
void readOriginalFile()
{
	FILE *filePointer;
	struct account *current;
	struct account *latest;
	char line[200];

	filePointer = fopen("c:\\Results.txt", "r");
	if (NULL == filePointer)
	{
		perror("Error: ");
	}
	else
	{
		fgets(line, 200, filePointer);
		while (!feof(filePointer))
		{
			if (feof(filePointer))
			{
				break;
			}
			current = (struct account*)malloc(sizeof(struct account));
			fscanf(filePointer, "%d\t%s\t%s\t%c\t%c\t%c\t%c", &current->ID, current->firstname, current->surname,
				&current->english, &current->maths, &current->french, &current->philosphy);
			if (NULL == first)
			{
				first = current;
				latest = current;
			}
			else
			{
				latest->next = current;
				latest = current;
			}
		}
	}
}


void writeData()
{
	FILE *fp;
	int j = 0;

	fp = fopen("accounts.dat", "wb+");
	if (NULL == fp)
	{
		perror("Error!");
	}
	for (j = 0; j < (entries - 2); j++)
	{
		fwrite(&first, sizeof(struct account), 1, fp);
		first = first->next;
	}

	fclose(fp);

}

void readData()
{
	FILE *fp;

	struct account *last = NULL;

	fp = fopen("accounts.dat", "rb+");

	while (!feof(fp))
	{
		last = (struct account *)malloc(sizeof(struct account));
		fread(last, sizeof(struct account), 1, fp);
		binary = last;
		binary->next = last;

	}

	fclose(fp);

}

void findRecord(int id)
{
	binary = first;
	while (binary != NULL)
	{
		if (binary->ID == id)
		{
			printf("First Name: %s\n Surname: %s\n Student ID: %d\n English: %c\n French: %c\n Maths: %c\n Philosphy: %c\n", binary->firstname, binary->surname, binary->ID, binary->english,
				binary->french, binary->maths, binary->philosphy);
			return;
		}
		binary = binary->next;
	}
}