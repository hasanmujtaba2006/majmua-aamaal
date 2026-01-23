#include<stdio.h>

int main(){
    int a[5]={2,4,7,6,1};

    int odd = 0,even = 0;

    for (int i=0;i<=4;i++){
        if (i%2==0){
            even=even+a[i];
        }
        else{
            odd=odd+a[i];
        }
    }
    printf("%d",even-odd);
    return 0;
} 