#include<stdio.h>

int main(){
    int a[5];

    int x = a[0];

    for (int i=0;i<5;i++){
        if (x>a[i]){
            x = a[i];
        }
    }

    printf("Minimum element : %d",x);
    return 0;
}