#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    printf("\nReverse Array : ");

    for (int k=0,l=n-1;k<l;k++,l--){
        int temp = a[k];
        a[k] = a[l];
        a[l] = temp;
    }

    for (int s=0;s<n;s++){
        printf("%d ",a[s]);
    }

    return 0;
}