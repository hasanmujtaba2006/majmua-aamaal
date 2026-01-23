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

    int evensum=0,oddsum=0;

    for (int i=0;i<n;i++){
        if (i%2==0){
            evensum+=a[i];
        }
        else{
            oddsum+=a[i];
        }
    }

    printf("\nThe difference b/w sum of elements at even indices and odd indices : %d",evensum-oddsum);
    return 0;
}