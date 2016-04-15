// Individual Project by Eamonn Hannon
// TODO:
// 1) Figure out how to actually get this working as I am SO CLOSE!!!!!!
// (the rest of these are optional) 2) maybe have a help function to give players the rules of the game?

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void readInDictionary(char *string[]);
void generateLetter(char *result[]);
void findLongestWord(char *dictionary[], char *letters[]);
void sortDictionary(char *dictionary[], char *limitedDictionary[], int wordSize);
int uniqueChars(char *string);

int sizeOfDictionary;

void main()
{
	char startStop[3] = "c";
	int i = 0;
	char userWord[10];
	char *inputResults[10] = { "c", "a" };
	char *testResults[10] = {"a","b","a","s","h","e","d", "a"};//abashed
	char *string[80000] = { "100", "200", "300", "400", "500", "600", "700", "800", "900", "100" };
	//above seems to be the best way to handle an array of strings. Not the only way, but the best.
	int k = 0;
	readInDictionary(string);
	//printf("%s", *(string));
	do
	{
		k++;
		printf("--------------------Welcome  to-------------------------\n");
		printf("---------------------COUNTDOWN--------------------------\n");
		/*
		____ ___  _   _ _   _ _____ ____   _____        ___   _
		/ ___/ _ \| | | | \ | |_   _|  _ \ / _ \ \      / / \ | |
		| |  | | | | | | |  \| | | | | | | | | | \ \ /\ / /|  \| |
		| |__| |_| | |_| | |\  | | | | |_| | |_| |\ V  V / | |\  |
		\____\___/ \___/|_| \_| |_| |____/ \___/  \_/\_/  |_| \_| <- might use that for logo, but have to ask Owen if using
		a generator for this type of art is OK
		*/
		printf("It's time for game %d!\n", k);
		generateLetter(inputResults);
		printf("\nIt's time for you to enter your word. Then the program will find the longest\n word it can from the dictionary.\n");
		fgets(userWord, sizeof(userWord), stdin);
		sscanf(userWord, "%s", userWord);
		printf("Your word was: %s\n", userWord);
		findLongestWord(string, inputResults);
		printf("Do you want to play again (y) or not? (n)\n");
		fgets(startStop, sizeof(startStop), stdin);
		sscanf(startStop, "%s", startStop);
	} while (strcmp(startStop, "n") != 0);
	//free(string);
	//free(inputResults);
	return;
}

void readInDictionary(char *string[])
{
	FILE *filePointer;
	int i = 0;
	char buffer[10] = "foo";
	if (NULL == (filePointer = fopen("webster.txt", "r")))
	{
		perror("Error!");
	}
	else
	{
		while (fgets(buffer, 10, filePointer))
		{
			if (ferror(filePointer))
			{
				break;
			}
			*(string+i) = (char *)malloc(10 * sizeof(char));
			strcpy(*(string + i), buffer);
			//printf("%s", *(string + i));
			i++;
		}
	}
	sizeOfDictionary = i;
	printf("Size of dictionary: %d", i);
	fclose(filePointer);
}

void generateLetter(char *result[])
{
	char *vowels[5] = { "a","e","i","o","u" };
	char *consonants[21] = {"b", "c", "d","f", "g", "h","j", "k", "l", "m", "n", "p", "q", "r", "s", "t","v", "w", "x", "y", "z"};
	int i = 0;
	int k = 0;
	char buffer[3] = "c";
	char choice = 'c';
	time_t t;
	srand(time(&t));
	//generates one vowel automatically.
	printf("Choose between a vowel (v) or constenant (c) when asked.\n One vowel will be automatically generated for you.\n");
	*(result + i) = (char *)malloc(2 * sizeof(char));
	k = rand() % 5;
	strcpy(*(result + i), *(vowels + k));
	//printf("%s", *(result + i));
	printf("That first vowel is: %s\n", *(result+0));
	for (i = 1; i < 8; i++)
	{
		*(result + i) = (char *)malloc(2 * sizeof(char));
		printf("Vowel or consonant?\n");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%c", &choice);
		switch ((choice))
		{
		case 'v':
			k = (rand() % 5);
			strcpy(*(result + i), *(vowels + k)); 
			printf("The vowel is: %s\n", *(result+i));
			break;
		case 'c':
			k = (rand() % 21);
			strcpy(*(result + i), *(consonants + k));
			printf("The constonant is: %s\n", *(result + i));
			break;
		default:
			printf("Error: wrong character entered! Randomly generating a consonant.\n");
			k = (rand() % 21) + 1;
			strcpy(*(result + i), *(consonants + k));
			printf("The consonant is: %s\n", *(result + i));
		}
	}
}

void findLongestWord(char *dictionary[], char *letters[])
{
	int i = 0;
	int k = 0;
	int j = 0;
	int uniqueLetters = 0;
	int uniqueInputs = 0;
	char inputs[8];
	char word[9] = "lol";
	char *limitedDictionary[45000] = { "lol", "rofl" };
	for (i = 0; i < 45000; i++)
	{
		*(limitedDictionary + i) = (char *)malloc(8 * sizeof(char));
	}
	for (i = 0; i < 8; i++)
	{
		inputs[i] = **(letters + i);
		//printf("%c\n", inputs[i]);
	}
	uniqueInputs = uniqueChars(inputs);
	for (k = 2; k < 9; k++)
	{
		sortDictionary(dictionary, limitedDictionary, k);
		for (i = 0;  i < 45000; i++)
		{
			uniqueLetters = uniqueChars(*(limitedDictionary)+i);
			if (*(limitedDictionary + i) == NULL)
			{
				break;
			}
			else if ((j = strspn(*(limitedDictionary+i), inputs)) == k-1 && uniqueLetters == (uniqueInputs - (9 - strlen(*(limitedDictionary+i)))))
			{
				//printf("Number of unique letters in inputs. %d\n", (uniqueInputs - (9 - strlen(inputs))));
				//printf("Number of unique letters in string. %d\n", uniqueLetters);
				strcpy(word, *(limitedDictionary+i));
			}
			//I believe I got it. What was wrong was that I was using 9 - k instead of 9 - 
			//strlen(*(limitedDictionary+i)); that seemed to work.
		}
	}
	if (strcmp("lol", word) == 0)
	{
		printf("Unfortunately, no word could be found in the dictionary from the letters\n provided.\n");
	}
	else
	{
		printf("The longest word found was: %s\n", word);
	}
	printf("Thank you for playing COUNTDOWN!\n");
}

void sortDictionary(char *dictionary[], char *limitedDictionary[], int wordSize)
{
	int i = 0;
	int k = 0;
	for (i = 0; i < sizeOfDictionary; i++)
	{
		if (strlen(*(dictionary + i)) == wordSize)
		{
			strcpy(*(limitedDictionary + k), *(dictionary + i));
			k++;
		}
	}
}

int uniqueChars(char * string)
{
	int count = 0;
	int i = 0;
	int j = 0;
	bool unique = false;
	for (i = 0; i < strlen(string); i++)
	{
		unique = false;
		for (j = 0; j < i; j++)
		{
			if (string[j] == string[i])
			{
				unique = true;
				break;
			}
		}
		if (!unique)
		{
			count = count + 1;
		}

	}
	count = count - 1;
	//printf("Number of unique letters in %s: %d\n", string, count);
	return count;
}