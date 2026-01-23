#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        for (int j=1;j<=5-i;j++){
            printf("  ");
        }

        for (int l=1;l<=i;l++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}