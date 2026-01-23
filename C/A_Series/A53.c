#include<stdio.h>

int main(){
    for (int i=1;i<=4;i++){
        int a=65;
        for (int j=1;j<=4;j++){
            printf("%c ",(char)a);
            a++;
        }
        printf("\n");
    }

    return 0;
}