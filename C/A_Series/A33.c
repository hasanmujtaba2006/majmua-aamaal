#include<stdio.h>
#include<stdbool.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    bool flag = false;

    for (int i=2;i<=(a-1);i++){
        if (a%i!=0){
            flag = true;
        }

        else{
            flag = false;
        }
    }

    if (flag=true){
        printf("%d is a prime number...",a);
    }

    else if (flag=false){
        printf("%d is not a prime number...",a);
    }

    return 0;
}