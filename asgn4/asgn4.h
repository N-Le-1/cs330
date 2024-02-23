#ifndef __asgn4__
#define __asgn4__
/* the two lines above check to ensure
we haven't already included this header*/

/* ========================================================================= */
/* ~~~~~~~~~~~~~~~~~~~~~ your functions go here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Note: main() goes in the asgn4.c file                                     */

/*
INSERTION SORT

Input: 2 different inputs. One includes the array the user wishes to sort. The second input is the size 
of the array.

Output: The output is the users inputted array sorted using insertion sort.

Description: The function will iterate through the full given array. For each
element, it will store the value into the "key" value which is a temporary place
holder for the current number in the array. The function will then eneter into a 
while loop which will iterate through the array until j >= 0 which means it is at 
the end of the array OR the key value is less than the value at arr[j]. This loop 
will shift elements to the right until it finds the correct position for the key 
value. Once this loop is finished, the array will finally be sorted. 

*/
void insertionSort(int arr[], int size){
    for(int i =1; i<size; i++){
        int key = *(arr+i);
        int j = i-1;
        while(j >= 0 && key < *(arr+j)){
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = key;
    }
}
/*
SELECTION SORT

Input: The input includes 2 variables. One variable is the array inputted by the user. The second variable
is the size of the given array.

Output: The output is the given array by the user, but sorted using selection sort algorithm.

Description: This function will iterate through the given array and sort it out till it is in 
numerical order. For each iteration, the function will initialize a variable called "minValueIndex" 
with the current index. The function will then compare the value at arr[j] with the value at 
arr[minValueIndex]. If the value of arr[j] is smaller than arr[minValueIndex],it will update the value
of minValueIndex to j. Once the loop finds the minimum value's index, the function will then check if 
minValueIndex is different from the value of i. If they are different, i and minValueIndex will swap 
positions. Once each iteration is complete, the array will finally be sorted.

*/

void selectionSort(int arr[], int size){
    for(int i=0; i< size-1; i++){
        int minValueIndex = i;
        for(int j = i+1; j<size; j++){
            if(*(arr+j) < *(arr + minValueIndex)){
                minValueIndex =j;
            }
        }
        //SWAP
        if(minValueIndex != i){
            int temp = *(arr + i);
            *(arr+i) = *(arr+minValueIndex);
            *(arr+minValueIndex) = temp;
        }
    }
}

#endif
