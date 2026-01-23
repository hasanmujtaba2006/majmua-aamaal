#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    for (int i=0;i<5;i++){
        if (i%2==0){
            a[i] = a[i]*2;
        }

        if (i%2!=0){
            a[i] = a[i]+10;
        }
    }

    printf("The Array : ");

    for (int j=0;j<5;j++){
        printf("%d ",a[j]);
    }

    return 0;
}