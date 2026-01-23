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

    int max=a[0],smax=a[0];

    for (int i=0;i<n;i++){
        if (a[i]>max){
            max = a[i];
        }
    }

    for (int j=0;j<n;j++){
        if (a[j]!=max && a[j]>smax){
            smax = a[j];
        }
    }

    printf("\nThe second maximum element : %d",smax);
    return 0;
}