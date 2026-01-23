#include<stdio.h>

int nterm(int n){
    if (n==0){
        return 1;
    }
    printf("%d\n",n);
    return nterm(n-1);
}
int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    nterm(n);

    return 0;
}