#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    int max = a[0],s_max = a[0];

    for (int i=0;i<5;i++){
        if (max<a[i]){
            max = a[i];
        }
    }

    for (int i=0;i<5;i++){
        if (a[i]<max && a[i]>s_max){
            s_max = a[i];
        }
    }

    printf("The second largest element in the array is %d ..",s_max);
    return 0;
}