#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int a=0;

    for (int i=2;i<n;i++){
        if ( n == 2 ){
            a = 1;
        }
        if ( n != 2 ){
            if (n%i!=0){
                a = 1;
            }

            if (n%i==0){
                a = 0;
            }
        }
    }

    if (a == 1){
        printf("Prime Number ..");
    }

    if (a == 0){
        printf("Not Prime Number ..");
    }

    return 0;
}