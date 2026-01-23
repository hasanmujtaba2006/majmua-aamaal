#include<stdio.h>

void primefact(int x){
    printf("The prime factors : ");
    for (int i=1;i<=x;i++){
        if (x%i==0){
            printf("%d ",i);
        }
    }
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    primefact(n);

    return 0;
}