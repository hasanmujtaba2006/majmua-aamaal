#include<stdio.h>

int main(){
    for (int i=1;i<=5;i++){
        for (int j=1;j<=5;j++){
            if (i==(6)/2 || j==6/2){
                printf("* ");
            }

            else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}