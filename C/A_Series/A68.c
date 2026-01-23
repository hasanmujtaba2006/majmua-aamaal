#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        int a=65,b=63+i;
        for (int j=1;j<=5-i;j++){
            printf("  ");
        }

        for (int k=1;k<=i;k++){
            printf("%c ",(char)a);
            a++;
        }

        for (int l=1;l<=i-1;l++){
            printf("%c ",(char)b);
            b--;
        }
        printf("\n");
    }

    return 0;
}