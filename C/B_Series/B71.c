#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        
        if (i==1){
            for (int s=1;s<=9;s++){
                printf("* ");
            }
        }

        if (i>1){
            for (int k=1;k<=5-i;k++){
                printf("* ");
            }

            for (int j=1;j<=2*i-1;j++){
                printf("  ");
            }

            for (int l=1;l<=5-i;l++){
                printf("* ");
            }

            
        }
        printf("\n");
    }

    return 0;
}