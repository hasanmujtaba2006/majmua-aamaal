#include<stdio.h>

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element [%d] : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Original Array : ");

    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\nReverse Array : ");

    for (int j=n-1;j>=0;j--){
        printf("%d ",a[j]);
    }

    return 0;
}