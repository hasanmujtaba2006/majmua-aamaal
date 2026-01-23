#include<stdio.h>

int main(){
    int n;
    printf("Enter number of rows of 1st Matrix : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns of 1st Matrix and Rows of 2nd Matrix : ");
    scanf("%d",&m);

    int p;
    printf("Enter number of columns of 2nd Matrix : ");
    scanf("%d",&p);

    int a[n][m],b[m][p],c[n][p];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter Element of Matrix 1 : ");
            scanf("%d",&a[i][j]);
        }
    }

    printf("The Matrix 1 : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<p;j++){
            printf("Enter Element of Matrix 2 : ");
            scanf("%d",&b[i][j]);
        }
    }

    printf("The Matrix 2 : \n");

    for (int i=0;i<m;i++){
        for (int j=0;j<p;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<p;j++){
            c[i][j] = 0;
            for (int k=0;k<m;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("The Multiplication of Matrix 1 and 2  : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<p;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}