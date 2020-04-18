#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "additionalFunctions.h"
#include "file_helper.h"
#define MAXRIDERS 5000

void clear(void)
{
	while (getchar() != '\n');
}

int getInt(void)
{
	char nl = 'x';
	int value;
	while (nl != '\n')
	{
		scanf("%d%c", &value, &nl);
		if (nl != '\n')
		{
			clear();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;

}

int getIntRange(int min, int max)
{
	int integer;
	do {
		integer = getInt();
		if (integer > max || integer < min) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (integer > max || integer < min);
	return integer;
}


int getCategory(void)
{
	char answer;
	char nl = '\n';
	printf("\n");
	printf("Choose a category S, M or L:>");
	scanf("%c%c", &answer, &nl);
	if (nl != '\n')
	{
		clear();
	}
	while ((answer != 's' && answer != 'S' && answer != 'm' && answer != 'M' && answer != 'l' && answer != 'L') || (nl != '\n'))
	{
		printf("*** INVALID ENTRY *** <Only (S)hort, (M)edium or (L)arge are acceptable>: ");
		scanf("%c%c", &answer, &nl);
		if (nl != '\n') {
			clear();
		}
	}
	if (answer == 's' || answer == 'S') {
		printf("you selected: %c\n", answer);
		return 1;
	}
	else if (answer == 'm' || answer == 'M') {
		printf("you selected: %c\n", answer);
		return 2;
	}
	else if (answer == 'l' || answer == 'L') {
		printf("you selected: %c\n", answer);
		return 3;
	}
	else return 0;
}

int menu(void)
{
	int selection;

	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a catergory\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
	printf("\n");
	printf("Select an option:> ");
	do {
		selection = getInt();
		if (selection > 4 || selection < 0)
		{
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 4>: ");
		}
	} while (selection > 4 || selection < 0);

	return selection;
}

void riderSystem(void)
{
	struct RiderInfo info[MAXRIDERS] = { {'\0'} };
	int selection;
	int answer = 0;
	int i;
	FILE* data = NULL;
	data = fopen("data.txt", "r");


	for (i = 0; i < MAXRIDERS; i++)
	{
		if (feof(data) == 0)
		{
			readFileRecord(data, &info[i]);
		}

	}
	fclose(data);
	while (answer == 0)
	{
		selection = menu();
		switch (selection)
		{
		case 1:
			shortascend(info);
			topthree(info);
			printf("\n");
			break;
		case 2:
			shortascend(info);
			getdistance(info);
			printf("\n");
			break;
		case 3:
			descend(info);
			getbotthree(info);
			printf("\n");
			break;
		case 4:
			shortascend(info);
			getwinners(info);
			printf("\n");
			break;
		case 0:
			printf("Keep on Riding!");
			printf("\n");
			answer = 1;
			break;
		default: 
			break;

		} 
	}
}



void displayType(void)
{
	int i;
	struct RiderInfo info[MAXRIDERS];
	FILE* data = NULL;
	data = fopen("data.txt", "r");
	
	
	for (i = 0; i < MAXRIDERS; i++) 
	{
		if (feof(data) == 0) 
		{
			readFileRecord(data, &info[i]);
		}
				
	}
	fclose(data);
}

void getdistance(struct RiderInfo* info)
{
	int a, i;
	a = getCategory();
	header1();
	for (i = 0; i < MAXRIDERS; i++)
	{
		if (a == 1)
		{
			getShortW(&info[i]);
		}
		else if (a == 2)
		{
			getMedW(&info[i]);
		}
		else if (a == 3)
		{
			getLongW(&info[i]);
			//getlong(&info[i]);
		}
	}
}

void getshort(struct RiderInfo* info)
{
	if (info->raceLength == 'S')
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		printf("\n");
	}
		
}

void getmedium (struct RiderInfo* info)
{
	if (info->raceLength == 'M') 
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		printf("\n");
	}
}

void getlong(struct RiderInfo* info)
{
	if (info->raceLength == 'L')
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		printf("\n");
	}
}
void getShortW(struct RiderInfo* info)
{
	if (info->raceLength == 'S')
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		withdrawn(info);
		printf("\n");
	}
}
void getMedW(struct RiderInfo* info)
{
	if (info->raceLength == 'M')
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		withdrawn(info);
		printf("\n");
	}
}
void getLongW(struct RiderInfo* info)
{
	if (info->raceLength == 'L')
	{
		printf("%-26s", info->name);
		printAge(info);
		convert(info);
		withdrawn(info);
		printf("\n");
	}
}

void long4(struct RiderInfo* info)
{
	if (info->raceLength == 'L')
	{
		printf("%-26s", info->name);
		printAge(info);
		printCat(info);
		convert(info);
		printf("\n");
	}
}

void short4(struct RiderInfo* info)
{
	if (info->raceLength == 'S')
	{
		printf("%-26s", info->name);
		printAge(info);
		printCat(info);
		convert(info);
		printf("\n");
	}
}

void med4(struct RiderInfo* info)
{
	if (info->raceLength == 'M')
	{
		printf("%-26s", info->name);
		printAge(info);
		printCat(info);
		convert(info);
		printf("\n");
	}
}
//Print&Header Functions:

void printAge(struct RiderInfo* info)
{
	char agegrp[8];
	if (info->age >= 35)
	{
		strcpy(agegrp, "Senior");
	}
	else if (info->age < 35 && info->age >= 21)
	{
		strcpy(agegrp, "Adults");
	}
	else if (info->age <= 20 && info->age >= 16)
	{
		strcpy(agegrp, "Juniors");
	}
	printf(" %7s", agegrp);
}

void withdrawn(struct RiderInfo* info)
{
	char wd[4];
	if (info->withdrawn == '\0') 
	{
		strcpy(wd, "No");
	}
	else{
		strcpy(wd, "Yes");
	}
	printf("%9s", wd);
}


void printCat(struct RiderInfo* info)
{
	char cat[7];

	if (info->raceLength == 'S') {
		strcpy(cat, "50 km");
	}
	else if (info->raceLength == 'M') {
		strcpy(cat, "75 km");
	}
	else if (info->raceLength == 'L') {
		strcpy(cat, "100 km");
	}
	printf("%9s", cat);
}

void convert(struct RiderInfo* info)
{
	double rt = info->finishTime - info->startTime;
	int tMin = rt * (double)60;
	int h = tMin / 60;
	int m = tMin % 60;
	char tw[4];
	if (info->withdrawn == '\0')
	{
		printf(" %1d:%02d", h, m);
	}else if (info->withdrawn != '\0')
	{
		strcpy(tw, "N/A");
		printf("%5s", tw);
	}
}

//header with age group, time, withdrew
void header1(void)
{
	printf("\n");
	printf("Rider                    Age Group Time Withdrew\n");
	printf("------------------------------------------------\n");
}
//header with age group, time
void header2(void)
{
	printf("\n");
	printf("Rider                    Age Group Time\n");
	printf("---------------------------------------\n");

}
//header with age group, category, time
void header3(void) {
	printf("\n");
	printf("Rider                    Age Group Category Time\n");
	printf("------------------------------------------------\n");
}

//Sort Functions:

void shortascend(struct RiderInfo* info)
{
	int i, j;
	struct RiderInfo sorttemp;
	for (i = 0; i < 5000; i++) {
		for (j = i + 1; j < 5000; j++) {
			if ((info[j].finishTime) > (info[i].finishTime))
			{
				sorttemp = info[j];
				info[j] = info[i];
				info[i] = sorttemp;
			}
		}
	}
}

void descend(struct RiderInfo* info)
{
	int i, j;
	struct RiderInfo sorttemp;
	for (i = 0; i < 5000; i++) {
		for (j = i + 1; j < 5000; j++) {
			if ((info[j].finishTime) < (info[i].finishTime))
			{
				sorttemp = info[j];
				info[j] = info[i];
				info[i] = sorttemp;
			}
		}
	}
}

void getbotthree(struct RiderInfo* info)
{
	int a, i;
	int j = 0;
	a = getCategory();
	header2();
	for (i = 0; i < MAXRIDERS; i++)
	{
		if (a == 1 && info[i].withdrawn == '\0' && j < 3 && info[i].raceLength == 'S')
		{
			getshort(&info[i]);
			j++;
		}
		else if (a == 2 && info[i].withdrawn == '\0' && j < 3 && info[i].raceLength == 'M')
		{
			getmedium(&info[i]);
			j++;
		}
		else if (a == 3 && info[i].withdrawn == '\0' && j < 3 && info[i].raceLength == 'L')
		{
			getlong(&info[i]);
			j++;
		}
	}
}


void topthree(struct RiderInfo* info)
{	int a, i;
	int j = 0;
	
	a = getCategory();
	header2();
	for(j; j<3;){
		for (i = 0; i < MAXRIDERS; i++)
		{

			if (a == 1 && j < 3 && info[i].raceLength == 'S')
			{
				getshort(&info[i]);
				j++;
			}
			else if (a == 2 && j < 3 && info[i].raceLength == 'M')
			{
				getmedium(&info[i]);
				j++;
			}
			else if (a == 3 && j < 3 && info[i].raceLength == 'L')
			{
				getlong(&info[i]);
				j++;
			}
		}
	}
}


void getwinners(struct RiderInfo* info)
{
	int i;
	int L = 1, M = 1, S = 1;
	int j = 0;
	header3();
	for (i = 0; i < MAXRIDERS; i++)
	{
		if (info[i].raceLength == 'L' && j < 3 && L == 1)
		{
			long4(&info[i]);
			L = 0;
			j++;
		}
		else if (info[i].raceLength == 'M' && j < 3 && M == 1)
		{
			med4(&info[i]);
			j++;
			M = 0;
		}
		else if (info[i].raceLength == 'S' && j < 3 && S == 1)
		{
			short4(&info[i]);
			j++;
			S = 0;
		}
	}
}






