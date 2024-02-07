#include <stdio.h>
#ifndef _NUMCLASS_H
#define _NUMCLASS_H


void scanMatrix();
int ifHasPath(int i,int j);
void floydWarshall();
void printMatrix();
int printLength(int k,int s);
int getInput();
int knapSack (int weights[], int values[] , int selected_bool[]);


#endif 