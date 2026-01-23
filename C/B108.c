#include<stdio.h>

int main(){
    int n;
    printf("Enter number of element : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    int x;
    printf("Enter element to find : ");
    scanf("%d",&x);

    int l=0,idx=0;
    for (int j=0;j<n;j++){
        if (a[j]==x){
            l = 1;
            idx = j;
        }

        if (a[j]!=x){
            l = 0;
        }
    }

    if (l==1){
        printf("Yes, %d is found in the array at %d ..",x,idx);
    }

    if (l==0){
        printf("No, %d is not found in the array ..",x);
    }

    return 0;
}