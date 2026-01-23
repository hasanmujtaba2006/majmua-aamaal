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

    for (int i=1;i<=n-1;i++){
        int j=i;
        while (j>0 && a[j]<a[j-1]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }

    int k;
    printf("\nEnter kth number : ");
    scanf("%d",&k);

    printf("\nThe %dth smallest element in the array is %d",k,a[k-1]);
    return 0;
}