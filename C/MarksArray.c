#include<stdio.h>

int main(){
    int marks[10];

    for (int i=0;i<=9;i++){
        printf("\nEnter marks of Roll no. %d : ",i);
        scanf("%d",&marks[i]);
    }

    for (int j=0;j<=9;j++){
        if (marks[j]<35){
            printf("%d,",j);
        }
    }
    return 0;
}