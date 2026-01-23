#include<stdio.h>

int main(){
    int a[5];

    int max = a[0];
    for (int i=0;i<5;i++){
        if (max<a[i]){
            max = a[i];
        }
    }

    printf("The maximum element : %d",max);
    return 0;
}