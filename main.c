/*
 * Thi tuyen
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/* struct */
typedef struct
{
	int sbd;
	int diem;
	char ten[15];
}
sv;

typedef struct 
{
	int size;
	sv all[2000];
}
danhsach;

danhsach a;
/* prototype */

/* main function */
int main(void)
{
	//open input for reading
	FILE* input = fopen("THITUYEN.INP", "r");
	if (input == NULL)
	{
		printf("Could not open file !\n");
		return 1;
	}
	
	int n;
	char buffer[20];
	//read N from input
	fscanf(input, "%d", &n);
	
	//read list from input
	a.size = 0;
	while (!feof(input))
	{
		fscanf(input, "%s%d%d", a.all[a.size].ten, &a.all[a.size].sbd, &a.all[a.size].diem);
		a.size++;
	}
	
	//try to print input file to stdout
	int i = 0;
	for (i = 0; i < a.size; i++)
		printf("%s   %d   %d\n", a.all[i].ten, a.all[i].sbd, a.all[i].diem);
		
	//sort list use bubble sort
	bool swap = true;
	while (swap)
	{
		swap = false;
		for (i = 0; i < a.size - 1; i++)
		{
			if (a.all[i].diem > a.all[i+1].diem)
			{
				//tmp
				sv tmp;
				//swap
				strcpy(tmp.ten ,a.all[i].ten);
				tmp.sbd = a.all[i].sbd;
				tmp.diem = a.all[i].diem;
				
				strcpy(a.all[i].ten, a.all[i+1].ten);
				a.all[i].sbd = a.all[i+1].sbd;
				a.all[i].diem = a.all[i+1].diem;
				
				strcpy(a.all[i+1].ten, tmp.ten);
				a.all[i+1].sbd = tmp.sbd;
				a.all[i+1].diem = tmp.diem;
				swap = true;
			}
		}
	}
	
	//open output for writing
	FILE* output = fopen("THITUYEN.OUT", "w");
	
	//write to output
	fprintf(output, "%d\n", n);
	for (i = 0; i < a.size; i++)
	{
		//write sv to output if sv.diem > 0;
		if (a.all[i].diem != 0)
			fprintf(output, "%s %d %d\n", a.all[i].ten, a.all[i].sbd, a.all[i].diem);
	}	
	//close all file when sucessfull
	fclose(input);
	fclose(output);
	return 0;
}















