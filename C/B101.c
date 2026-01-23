#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    int x;
    printf("Enter number whose sum pair you want : ");
    scanf("%d",&x);

    int n=0,m=0;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            if (a[i]+a[j]==x){
            n = a[i];
            m = a[j];
            }
        }
    }

    printf("The pairs of number (%d,%d) is equal to %d ..",n,m,x);

    return 0;
}