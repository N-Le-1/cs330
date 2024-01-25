#include <stdio.h>
#include <math.h>
#include "asgn2.h"

int main(){
    //initialize variables
    int n, n2, n3 = 0;
    float x,y = 0;

    //Q. 1
    printf("***Question 1: cubeOfOdd \n");
    printf("Enter an integer value: \n");
    scanf("%d",&n);
    cubeOfOdd(n);

    //Q.2
    printf("***Question 2: introToCS330 \n");
    printf("Enter an integer value: \n");
    scanf("%d",&n);
    introToCS330(n);

    //Q.3
    printf("***Question 3: printHELLO*** \n");
    printf("Enter an integer value: \n");
    scanf("%d",&n);
    printHELLO(n);

    //Q.4
    printf("***Question 4: paintGallons*** \n");
    printf("Enter the length of the wall: \n");
    scanf("%d",&n);
    printf("Enter the width of the wall: \n");
    scanf("%d",&n2);
    printf("Enter the height of the wall: \n");
    scanf("%d",&n3);
    paintGallons(n,n2,n3);

    //Q.5
    printf("***Question 5: grader*** \n");
    printf("Enter your average exam grade: \n");
    scanf("%f",&x);
    printf("Enter your average homework grade: \n");
    scanf("%f",&y);
    printf("Enter your attendance: \n");
    scanf("%d",&n);
    grader(x,y,n);
    
    return 0;
    
}