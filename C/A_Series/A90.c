#include<stdio.h>

void preinpost(int n){
    if (n==0){
        return;
    }
    printf("\nPre : %d",n);
    preinpost(n-1);
    printf("\nIn : %d",n);
    preinpost(n-1);
    printf("\nPost : %d",n);
    return;
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    preinpost(n);
    return 0;
}