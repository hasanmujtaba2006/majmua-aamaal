#include<stdio.h>

void primefactors(int a){
    printf("Prime Factors : ");
    for (int i=1;i<=a;i++){
        if (a%i==0){
            printf("%d ",i);
        }
        else{
            continue;
        }
    }
    return;
}

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    primefactors(a);
    return 0;
}