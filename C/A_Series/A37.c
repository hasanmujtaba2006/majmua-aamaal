#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int ld=0,rn=0;

    while (n>0){
        ld = n%10;
        n = n/10;
        rn = rn*10+ld;
    }

    printf("The reverse number : %d",rn);

    return 0;
}