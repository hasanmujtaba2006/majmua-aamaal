#include <stdio.h>

int primefactor(int n){
    int factor;
    for (int i=1;i<=n;i++){
        if (n%i==0){
            factor = i;
            printf("%d ",factor);
        }
        else{
            continue;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int l = primefactor(n);
    printf("%d",l);
    return 0;
}