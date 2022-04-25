
#define _CRT_SECURE_NO_WARNINGS

#define OK                   0
#define ERR_NO_FILE			-1
#define ERR_FILE_EMPTY		-2
#define ERR_DATA			-3


#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

using namespace std;

int ReadStringToArrays(int*, char(*)[100], int*, int*, FILE*);
void WriteToFile(int numberWordsAndOdd, int numberEven, int* Even, char(*LettersAndOdd)[100], FILE* ptrNew);

int main()
{
	int* Even = (int*)malloc(100 * sizeof(int));
	char LettersAndOdd[100][100];
	int numberEven = 0;
	int numberWordsAndOdd = 0;

	/*
	FILE* ptr = fopen("file.txt", "r+");
	FILE* ptrNew = fopen("file_new.txt", "w+");
	*/
	char path_in[250];
	char path_out[250] = "file_new.txt";
	gets_s(path_in);
	FILE* fin = fopen(path_in, "r");
	FILE* fout = fopen(path_out, "w");

	if (fin == NULL)
	{
		fprintf(fout, "no such file.\n");
		printf("no such file");
		fclose(fout);
		return ERR_NO_FILE;
	}
	else
	{
		fseek(fin, 0, SEEK_END);
		unsigned int size = ftell(fin);
		if (size == 0)
		{
			fprintf(fout, "file is empty.\n");
			printf("file is empty.\n");
			fclose(fout);
			return ERR_FILE_EMPTY;
		}
		fseek(fin, 0, SEEK_CUR);
	}

	while (!feof(fin))
	{
		if (ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin) != 0)
		{
			fclose(fout);
			fopen("file_new.txt", "w");
			fprintf(fout, "%s", "Incorrect data.\n");
			printf("Incorrect data.\n");
			fclose(fout);
			return ERR_DATA;
		}
		WriteToFile(numberWordsAndOdd, numberEven, Even, LettersAndOdd, fout);
		memset(Even, 0, numberEven);
		memset(LettersAndOdd, ' ', numberWordsAndOdd);
		numberWordsAndOdd = 0;
		numberEven = 0;
	}
	fclose(fin);
	fclose(fout);
	free(Even);

	system("pause");

}

int ReadStringToArrays(int* Even, char(*LettersAndOdd)[100], int* numberEven, int* numberWordsAndOdd, FILE* ptr)
{
	char o;
	int num;
	int rc = OK;
	char d;
	while ((fscanf(ptr, "%c", &o) && (o != '\n')) && (!feof(ptr)))
	{
		fseek(ptr, -1, SEEK_CUR);

		if (fscanf(ptr, "%d", &num) != 0)
		{
			if (num % 2 == 0)
			{
				(Even[*(numberEven)]) = num;
				*(numberEven) = *(numberEven)+1;
			}
			else
			{
				_itoa(num, LettersAndOdd[*(numberWordsAndOdd)], 10);
				*(numberWordsAndOdd) = *(numberWordsAndOdd)+1;
			}

		}
		else
		{
			fscanf(ptr, "%c", &d);
			fseek(ptr, -1, SEEK_CUR);
			if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
			{
				(fscanf(ptr, "%s", LettersAndOdd[*(numberWordsAndOdd)]));
				*(numberWordsAndOdd) = *(numberWordsAndOdd)+1;
			}

			else
				return ERR_DATA;
		}
	}
	return rc;
}

void WriteToFile(int numberWordsAndOdd, int numberEven, int* Even, char(*LettersAndOdd)[100], FILE* ptrNew)
{
	for (int j = 0; j < numberWordsAndOdd; j++)
		fprintf(ptrNew, "%s ", LettersAndOdd[j]);

	for (int i = 0; i < numberEven; i++)
		fprintf(ptrNew, "%d ", Even[i]);
	fprintf(ptrNew, "%c", '\n');

}