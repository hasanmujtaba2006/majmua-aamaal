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

    printf("Original Array : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    int max = INT_MIN;

    for (int i=0;i<n;i++){
        if (a[i]>max){
            max = a[i];
        }
    }

    printf("\nThe maximum value in array : %d",max);
    return 0;
}