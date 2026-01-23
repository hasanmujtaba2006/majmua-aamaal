#include<stdio.h>

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int a[n][n];

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("Enter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    printf("The original Matrix : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0,k=n-1;j<k;j++,k--){
            int temp = a[i][j];
            a[i][j] = a[i][k];
            a[i][k] = temp;
        }
    }

    printf("The Matrix After 90 degree rotated : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}