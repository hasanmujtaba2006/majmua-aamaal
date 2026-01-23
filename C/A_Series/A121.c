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

    printf("Tranpose of Matrix : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }    
    return 0;
}