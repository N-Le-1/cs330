#include <stdio.h>
#include <stdlib.h>
#include "asgn4.h"

int main(){
    int size;

    printf("Enter the size of your array: ");
    scanf("%d",&size);

    int array[size];

    printf("Enter the %d numbers: ",size);
    for(int i=0; i< size; i++){
        scanf("%d",&array[i]);
    }

    int selection;

    printf("Enter the number that corresponds with which sorting algorithm you would like to use: \n");
    printf("1.) Insertion Sort \n2.) Selection Sort \n");
    scanf("%d",&selection);

    switch(selection){
        case 1:
            insertionSort(array,size);
            printf("Insertion Sort Completed! \n");
            break;
        
        case 2:
            selectionSort(array,size);
            printf("Selection Sort Completed! \n");
            break;

        default: 
            printf("Enter a valid number that corresponds with a searching algorithm\nBYE! :)\n");
            exit(0);
        }

    printf("[");

    for(int i=0; i<size;i++){
        printf("%d ", array[i]);
    }

    printf("]");

    return 0;
}
