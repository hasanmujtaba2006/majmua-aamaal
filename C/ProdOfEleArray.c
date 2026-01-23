#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    int prod = 1;

    for (int j=0;j<=(n-1);j++){
        prod = prod*a[j];
    }
    printf("The product of elements of array : %d",prod);
    return 0;
}