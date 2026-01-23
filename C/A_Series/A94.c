#include<stdio.h>

int main(){
    int a[10] = {98,33,45,67,83,22,11,87,23,42};

    printf("The Roll Numbers of students whose marks are less than 35 : ");

    for (int i=0;i<10;i++){
        if (a[i]<35){
            printf("%d ",i+1);
        }
    }

    return 0;
}