#include <stdio.h>

int main(){
    int a[7]={1,2,3,4,4,5,6};

    for (int i=0;i<=6;i++){
        for (int j=i+1;j<=6;j++){
            if (a[i]==a[j]){
                printf("%d is a duplicate number...",a[i]);
                break;
            }
        }
    }
    return 0;
} 