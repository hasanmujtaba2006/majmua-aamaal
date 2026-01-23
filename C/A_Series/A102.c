#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int x;
    printf("Enter a number : ");
    scanf("%d",&x);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }


    int count=0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (a[i]+a[j]+a[k]==x){
                    count++;
                }
            }
        }
    }

    printf("\nThe number of triplets : %d",count);
    return 0;
}