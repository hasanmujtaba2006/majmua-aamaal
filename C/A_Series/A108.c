#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    int x;
    printf("Enter element you want to search : ");
    scanf("%d",&x);
    int idx=0;

    for (int i=0;i<5;i++){
        if (a[i]==x){
            idx = i;
        }
    }

    printf("\n%d element found at %dth index..",x,idx);
    return 0;
}