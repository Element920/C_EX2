#ifndef _MY_MAT_H_
#define _MY_MAT_H_

#define V 10
#define knapsackCapacity 20
#define numberOfObjects 5

void matrixInsert(int mat[V][V]);

void isRoutable(int mat[V][V], int i, int j);

void shortest(int mat[V][V], int i, int j);

void floydWarshall(int mat[V][V]);

int max(int a, int b);

int knapsack( int weights[], int values[], int chosenObjects[]);

void getUserInput(char names[][50], int weights[], int values[]);

#endif



