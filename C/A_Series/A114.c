#include<stdio.h>


int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    int a[n][m],b[n][m],c[n][m];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter element for matrix 1 : ");
            scanf("%d",&a[i][j]);
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter element for matrix 2 : ");
            scanf("%d",&b[i][j]);
        }
    }

    printf("The Matrix 1 : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("The Matrix 2 : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            c[i][j] = a[i][j]+b[i][j];
        }
    }

    printf("The Matrix of sum of Matrix 1 and Matrix 2 : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}