#include <stdio.h>
#include "my_mat.h"


int main() 
{
    
    char names[numberOfObjects][50];
    int weights[numberOfObjects];
    int values[numberOfObjects];

    // Get user input for objects
    getUserInput(names, weights, values);

    // Array to store the indices of chosen objects
    int chosenObjects[numberOfObjects];

    // Call the knapsack function with user input
    int totalMaxValue = knapsack( weights, values, chosenObjects);

    printf("Total maximum value of chosen objects: %d\n", totalMaxValue);

    return 0;
}
