#include<stdio.h>
#include<limits.h>

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

    for (int i=0;i<=n-1;i++){
        int j = i;
        while (j>0 && a[j]<a[j-1]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }

    printf("\nThe sorted array : ");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}