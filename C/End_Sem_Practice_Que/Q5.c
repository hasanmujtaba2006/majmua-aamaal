#include<stdio.h>

int main(){
    int a[] = {1,2,3,4,5};

    int max_ele = a[0];

    for (int i=0;i<5;i++){
        if (a[i]>max_ele){
            max_ele = a[i];
        }
    }

    printf("Maximum element in the array is %d",max_ele);
    return 0;
}