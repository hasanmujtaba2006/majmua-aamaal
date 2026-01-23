#include<stdio.h>

int main(){
    int a[10];

    printf("Student who scored less than 35 marks : \n");
    for (int i=0;i<10;i++){
        if (a[i]<35){
            printf("%d ",i);
        }
    }

    return 0;
}