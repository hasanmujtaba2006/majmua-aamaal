#include<stdio.h>

int main(){
    int arr[5] = {1,2,3,4,5};

    int sum_ele = 0;

    for (int i=0;i<5;i++){
        sum_ele+=arr[i];
    }

    printf("Sum of elements of 1-D Array is %d ..",sum_ele);
    return 0;
}