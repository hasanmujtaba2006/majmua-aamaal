#include <stdio.h>

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    int a[n][m];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("\nEnter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    int max=-1,min=__INT_MAX__,k1=0,l1=0,k2=0,l2=0;

    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            if (a[k][l]>max){
                max=a[k][l];
                k1=k;
                l1=l;
            }

            if (a[k][l]<min){
                min=a[k][l];
                k2=k;
                l2=l;
            }
        }
    }
    printf("%d is max element at (%d,%d) and %d is min element at (%d,%d)..",max,k1,l1,min,k2,l2);
    return 0;
}