#include <stdio.h>
#include "file_helper.h"



void clear(void);

int menu(void);

int getIntRange(int min, int max);

void header1(void);

void header2(void);

void header3(void);

void riderSystem(void);

void displayType(void);

void convert(struct RiderInfo* info);

void printAge(struct RiderInfo* info);

void printCat(struct RiderInfo* info);

void getLongW(struct RiderInfo* info);
void getShortW(struct RiderInfo* info);
void getMedW(struct RiderInfo* info);

void short4(struct RiderInfo* info);
void med4(struct RiderInfo* info);
void long4(struct RiderInfo* info);

void withdrawn(struct RiderInfo* info);

void getdistance(struct RiderInfo* info);

void getshort(const struct RiderInfo* info);

void getmedium  (const struct RiderInfo* info);

void getlong(const struct RiderInfo* info);

void topthree(const struct RiderInfo* info);

void shortascend(struct RiderInfo* info);

void getwinners(struct RiderInfo* info);

void descend(struct RiderInfo* info);

void getbotthree(struct RiderInfo* info);




