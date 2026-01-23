#include<stdio.h>

int main(){
    int t;
    printf("Enter a target number : ");
    scanf("%d",&t);

    int n;
    printf("Enter size of element : ");
    scanf("%d",&n);

    int a[n],ele1,ele2;

    for (int i=0;i<n;i++){
        printf("\nEnter a element : ");
        scanf("%d",&a[i]);
    }

    for (int j=0;j<n;j++){
        for (int k=j+1;k<n;k++){
            if (a[j]+a[k]==t){
                ele1=a[j];
                ele2=a[k];
            }
        }
    }
    printf("The two elements in the array whose sum is %d are (%d,%d)",t,ele1,ele2);
    return 0;
} 