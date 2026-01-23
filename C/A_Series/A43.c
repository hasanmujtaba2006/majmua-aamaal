#include<stdio.h>

int main(){
    int n;
    printf("Enter base number : ");
    scanf("%d",&n);

    int m;
    printf("Enter power number : ");
    scanf("%d",&m);

    int rp = 1;

    for (int i=1;i<=m;i++){
        rp = rp * 2;
    }

    printf("%d raise the power %d is equal to %d",n,m,rp);

    return 0;
}