#include<stdio.h>

int nsteps(int n){
    if (n==1){
        return 1;
    }
    if (n==2){
        return 2;
    }
    return nsteps(n-1)+nsteps(n-2);
}

int main(){
    int n;
    printf("Enter number of stairs : ");
    scanf("%d",&n);

    printf("The total possible ways to reach top : %d",nsteps(n));
    return 0;
}