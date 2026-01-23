#include <stdio.h>

int stair(int n){
    if (n==1 || n==2 || n==3){
        return n;
    }
    return stair(n-1)+stair(n-2)+stair(n-3);
}

int main(){
    int n;
    printf("Enter number of stairs : ");
    scanf("%d",&n);

    printf("The number of ways : %d",stair(n));
    return 0;
}