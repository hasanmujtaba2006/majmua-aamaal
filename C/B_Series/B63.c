#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        int a = 65;
        for (int j=1;j<=5-i;j++){
            printf("  ");
        }

        for (int k=1;k<=i;k++){
            printf("%c ",(char)a);
            a++;
        }

        printf("\n");
    }

    return 0;
}