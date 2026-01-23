#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        int a=1;
        if (i==1){
            for (int s=1;s<=9;s++){
                printf("%d ",a);
                a++;
            }
        }
        if (i>=2){
            for (int j=1;j<=5-i;j++){
                printf("%d ",a);
                a++;
            }

            for (int k=1;k<=2*i-1;k++){
                printf("  ");
                a++;
            }

            for (int l=1;l<=5-i;l++){
                printf("%d ",a);
                a++;
            }
        }
        printf("\n");
    }
    return 0;
}