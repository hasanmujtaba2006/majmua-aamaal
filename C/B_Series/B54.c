#include<stdio.h>

int main(){
    for (int i=1;i<=5;i++){
        int a = 65;
        for (int j=1;j<=i;j++){
            if (i%2!=0){
                printf("%d ",j);
            }

            if (i%2==0){
                printf("%c ",(char)a);
                a++;
            }
        }
        printf("\n");
    }

    return 0;
}