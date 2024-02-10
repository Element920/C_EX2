#include <stdio.h>
#include "my_mat.h"


void floydWarshall(int mat[V][V]){ // algorithm for shortest way
    int a = 0, b = 0, sum = 0;

    for(int k = 0 ; k < V ; k++){
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                a = mat[i][k];
                b = mat[k][j];
                if(a != 0 && b != 0){
                    sum = a+b;
                }
                else {
                    sum = 0;
                }
                if(i != j){
                    if(sum == 0){
                        //do nothing
                    }
                    else if(mat[i][j] == 0){
                        mat[i][j] = sum;
                    }
                    else if(sum < mat[i][j]){
                        mat[i][j] = sum;
                    }
                }
            
            }
        }
    }
 
}


void matrixInsert(int mat[V][V]){ //insert the numbers to the matrix
    int num = 0;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            scanf("%d" , &num);
            mat[i][j] = num;
        }
    }

    floydWarshall(mat); 
}


void isRoutable(int mat[V][V] , int i , int j){ // checks if there is a way from A to B
    if(mat[i][j] == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}

void shortest(int mat[V][V] , int i , int j){ // checks the shortest way from A to B depends on the algorithm

    if(i == j && mat[i][j] == 1){
        printf("0\n");
    }
    else{
        if(mat[i][j] == 0){
        printf("-1\n");
        }
        else{
        printf("%d\n" , mat[i][j]);
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Part 2


int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using dynamic programming
int knapsack( int weights[], int values[], int chosenObjects[]) {
    int i, currentCapacity;
    int dpTable[numberOfObjects + 1][knapsackCapacity + 1];

    // Build a table dpTable[][] in a bottom-up manner
    for (i = 0; i <= numberOfObjects; i++) {
        for (currentCapacity = 0; currentCapacity <= knapsackCapacity; currentCapacity++) {
            if (i == 0 || currentCapacity == 0)
                dpTable[i][currentCapacity] = 0;
            else if (weights[i - 1] <= currentCapacity)
                dpTable[i][currentCapacity] = max(values[i - 1] + dpTable[i - 1][currentCapacity - weights[i - 1]], dpTable[i - 1][currentCapacity]);
            else
                dpTable[i][currentCapacity] = dpTable[i - 1][currentCapacity];
        }
    }

    // Find the selected items and calculate the total maximum value
    int maxValue = dpTable[numberOfObjects][knapsackCapacity];
    printf("Maximum value in the Knapsack: %d\n", maxValue);

    currentCapacity = knapsackCapacity;
    int count = 0;

    // Populate the array of chosen objects
    for (i = numberOfObjects; i > 0 && maxValue > 0; i--) {
        if (maxValue != dpTable[i - 1][currentCapacity]) {
            chosenObjects[count++] = i - 1;
            maxValue -= values[i - 1];
            currentCapacity -= weights[i - 1];
        }
    }

    // Print the list of chosen objects
    printf("Selected items:\n");
    for (i = count - 1; i >= 0; i--) {
        int index = chosenObjects[i];
        printf("(Weight: %d kg, Value: %d)\n", weights[index], values[index]);
    }

    return dpTable[numberOfObjects][knapsackCapacity];
}

// Function to get user input for objects
void getUserInput(char names[][50], int weights[], int values[]) {
    for (int i = 0; i < 5; i++) {
        printf("Enter the name of Object %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter the weight of Object %d (in kg): ", i + 1);
        scanf("%d", &weights[i]);
        printf("Enter the value of Object %d: ", i + 1);
        scanf("%d", &values[i]);
    }
}