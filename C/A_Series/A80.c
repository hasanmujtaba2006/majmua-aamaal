#include<stdio.h>

int nnum(int n){
    if(n==1){
        return 1;
    }
    printf("%d ",n);
    return nnum(n-1);
}

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    nnum(a);
    return 0;
}