#include<stdio.h>

int main(){
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    int a = 100;
    printf("Arithmetic Progression : ");
    for (int i=1;i<=n;i++){
        printf("%d ",a);
        a = a - 3;
    }

    return 0;
}