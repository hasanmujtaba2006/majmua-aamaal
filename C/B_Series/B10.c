#include<stdio.h>

int main(){
    int a;
    printf("Enter a integer both +ve and -ve numbers accepted : ");
    scanf("%d",&a);

    if (a>0){
        printf("The absolute value is %d..",a);
    }

    if (a<0){
        printf("The absolute value is %d..",-1*a);
    }

    else{
        printf("The absolute value is %d..",a);
    }

    return 0;
}