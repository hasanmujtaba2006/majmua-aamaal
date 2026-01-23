#include<stdio.h>

int main(){
    int a[5];

    int sum = 0;

    for (int i=0;i<5;i++){
        sum+=a[i];
    }

    printf("Sum of the elements of the array : %d",sum);

    return 0;
}