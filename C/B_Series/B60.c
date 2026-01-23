#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        for (int j=1;j<=i;j++){
            if ((i+j)%2!=0){
                printf("0 ");
            }

            if ((i+j)%2==0){
                printf("1 ");
            }
        }
        printf("\n");
    }

    return 0;
}