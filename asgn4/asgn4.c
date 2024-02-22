#include <stdio.h>
#include <stdlib.h>
#include "asgn4.h"

/*
Main function that will ask the user for their array size and the numbers they wish to put into their array.
Once the user inputs their array and array size, the program will ask the user which sorting algorithm they wish
to use to sort their array. The program will use a switch case to call the algorithm that the user selects and 
will print out the given sorted array.
*/

int main(){
    int size; //initialize variable for user input

    printf("Enter the size of your array: ");
    scanf("%d",&size);

    int array[size]; //initialize the array for user input

    printf("Enter the %d numbers: ",size);
    for(int i=0; i< size; i++){
        scanf("%d",&array[i]);
    }

    int selection; //initialize variable for switch case.

    printf("Enter the number that corresponds with which sorting algorithm you would like to use: \n");
    printf("1.) Insertion Sort \n2.) Selection Sort \n");
    scanf("%d",&selection);

    switch(selection){  //Switch statement that allows the user to select which alg. they would like to use.
        case 1:
            insertionSort(array,size);
            printf("Insertion Sort Completed! \n");
            break;
        
        case 2:
            selectionSort(array,size);
            printf("Selection Sort Completed! \n");
            break;

        default:  //Edge case if user picks number other than 1 or 2.
            printf("Enter a valid number that corresponds with a searching algorithm\nBYE! :)\n");
            exit(0);
        }

    printf("["); //Finally prints out the sorted array into the terminal.

    for(int i=0; i<size;i++){
        printf("%d ", array[i]);
    }

    printf("]");

    return 0;
}
