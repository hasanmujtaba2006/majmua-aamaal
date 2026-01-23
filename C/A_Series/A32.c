#include<stdio.h>

int main(){
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    float a=100;

    printf("The G.P. is : ");

    for (int i=1;i<=n;i++){
        printf("%f ",a);
        a=a*(0.5);
    }

    return 0;
}