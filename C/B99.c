#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};
    int x = 3,count = 0;

    for (int i=0;i<5;i++){
        if (a[i]>x){
            count++;
        }
    }

    printf("The number of elements greater than %d are %d ..",x,count);
    return 0;
}