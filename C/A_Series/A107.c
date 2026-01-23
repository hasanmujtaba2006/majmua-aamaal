#include<stdio.h>

void reverse(int a[],int si,int ei){
    int temp = a[si];
    a[si] = a[ei];
    a[ei] = temp;
    return;
}

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int k;
    printf("Enter kth step : ");
    scanf("%d",&k);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    reverse(a,0,n-1);
    reverse(a,0,k-1);
    reverse(a,k,n-1);

    printf("\nThe array after reversing from %dth step : ",k);

    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}