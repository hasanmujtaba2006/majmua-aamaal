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

    int ele1=0,ele2=0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (a[i]+a[j]==x){
                ele1 = a[i];
                ele2 = a[j];
            }
        }
    }

    printf("\nThe pairs are (%d,%d) whose sum equal to %d..",ele1,ele2,x);
    return 0;
}