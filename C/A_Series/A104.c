#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n],b[n];

    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array 1: ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    for (int i=0,j=n-1;i<j;i++,j--){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;  
    }

    for (int i=0;i<n;i++){
        b[i] = a[i];
    }

    printf("\nCopied Array 2 : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    return 0;
}