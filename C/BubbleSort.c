#include<stdio.h>
#include<stdbool.h>

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

    for (int k=0;k<n-1;k++){
        bool flag =true;
        for (int l=0;l<=n-1-i;l++){
            if(a[l]>a[l+1]){
                int temp = a[l];
                a[l] = a[l+1];
                a[l+1] = temp;
                flag = false;
            }
        }
        if (flag==true){
            break;
        }
    }

    printf("\nSorted Array:\n");

    for (int s=0;s<n;s++){
        printf("%d ",a[s]);
    }

    return 0;
}