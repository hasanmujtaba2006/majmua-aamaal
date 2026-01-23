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

    printf("Unsorted Array : ");

    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-2;j++){
            if (a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("\nThe sorted array : ");

    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}