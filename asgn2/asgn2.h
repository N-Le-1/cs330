#ifndef __asgn2__
#define __asgn2__

/* the two lines above check to ensure
we haven't already included this header*/


/* your functions go here */
// Note: main() goes in the asgn2.c file

int cubeOfOdd(){
    int n =0; 

    printf("***Question 1: cubeOfOdd***\n");
    printf("Enter a positive integer value: \n");
    scanf("%d",&n);


    if(n<=0){
        printf("Enter a positive integer value");
        return 0;
    }

    for(int i=1; i<n;i+=2){
        int cubed = pow(i,3);
        printf("%d \n", cubed);
    }
    return 0;
}

int primeNum(int num);

void introToCS330(){
    int n = 0;
    printf("***Question 2: introToCS330***\n");
    printf("Enter an integer value: \n");
    scanf("%d",&n);

    if(primeNum(n) && n!=3 && n!=7){
        printf("Go Blazers \n");
    }
    else if(n%3==0 && n%7==0){
        printf("UAB CS 330 \n");
    }
    else if(n%7==0){
        printf("UAB \n");
    }
    else if(n%3==0){
        printf("CS \n");
    }
    else{
        int cubed = pow(n,3);
        printf("%d \n", cubed);
    }
}
//Helper function for introToCS330
int primeNum(int num){
    if(num<=1){
        return 0;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int isPowerTwo(int num);

void printHELLO(){
    int n = 0;
    printf("***Question 3 printHELLO***\n");
    printf("Enter an integer value: \n");
    scanf("%d",&n);

    for(int i=0; i<=n; i++){
        if(isPowerTwo(i)){
            printf("HELLO");
        }
        else{
            printf("%d",i);
        }
    }
    printf("\n");
}
int isPowerTwo(int num){
    if(num==0){
        return 0;
    }
    while(num!=1){
        if(num%2 !=0){
            return 0;
        }
        num = num/2;
    }
    return 1;
}

float paintGallons(){
    int length,width,height = 0;

    printf("***Question 4 paintGallons***\n");
    printf("Enter the length of your wall: \n");
    scanf("%d",&length);
    
    printf("Enter the width of your wall: \n");
    scanf("%d",&width);

    printf("Enter the height of your wall: \n");
    scanf("%d",&height);

    // 1 gallon of paint covers 400 sq.ft 
    int sqFeet = 400;
    
    float walls = 2*(length*height);
    float walls2 = 2*(width*height);
    float ceiling = (width*length);
    
    float area = walls + walls2 + ceiling;
    
    float final = ceil(area / sqFeet);

    printf("%.1f \n",final);
    
    return final;
}

void grader(){
    
    float avg_exams, avg_hw = 0;
    int attendance = 0;

    printf("***Question 5 grader***\n");
    printf("Enter your average exam score: \n");
    scanf("%f",&avg_exams);
    
    printf("Enter your average homework score: \n");
    scanf("%f",&avg_hw);

    printf("Enter your attendance: \n");
    scanf("%d",&attendance);

    if(attendance > 20){
        if(avg_exams > 70 && avg_hw > 70){
            if(avg_exams > 85 || avg_hw > 85){
                 printf("PASS \n");
            }
            else{
                printf("FAIL \n");
            }
        }
        else{
            printf("FAIL \n");
        }
    }
    else{
        printf("FAIL \n");
    }
    
}

#endif