#include<stdio.h>
#include<limits.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];
 
    for (int i=0;i<n;i++){
        printf("Enter Element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array:\n");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    for (int i=0;i<n-1;i++){
        int min = INT_MAX;
        int minidx = -1;
        for (int j=i;j<=n-1;j++){
            if(min>a[j]){
                min = a[j];
                minidx = j;
            }
        }
        int temp = a[minidx];
        a[minidx] = a[i];
        a[i] = temp;
    }

    printf("\nSorted Array:\n");

    for (int s=0;s<n;s++){
        printf("%d ",a[s]);
    }
    return 0;
}