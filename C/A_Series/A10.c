#include<stdio.h>

int main(){
    int a;
    printf("Enter s number (+ve or -ve) : ");
    scanf("%d",&a);

    if (a<0){
        printf("The absolute value of %d is %d..",a,-1*a);
    }

    else{
        printf("The absolute value is %d",a);
    }

    return 0;
}