#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        if (i==1){
            for (int j=1;j<=9;j++){
                printf("%d ",j);
            }
        }

        if (i>1){
            int a=1;
            for (int k=1;k<=5-i;k++){
                printf("%d ",a);
                a++;
            }

            for (int l=1;l<=2*i-1;l++){
                printf("  ");
                a++;
            }

            for (int s=1;s<=5-i;s++){
                printf("%d ",a);
                a++;
            }
        }
        printf("\n");
    }

    return 0;
}