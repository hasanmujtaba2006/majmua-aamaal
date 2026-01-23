#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        for (int j=1;j<=5-i;j++){
            printf("  ");
        }

        int a = 65;

        for (int k=1;k<=2*i-1;k++){
            printf("%c ",(char)a);
            a++;
        }

        printf("\n");
    }

    return 0;
}