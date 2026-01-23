#include<stdio.h>

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
            printf("Enter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    printf("The original Matrix : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Tranpose of Matrix : \n");

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }    
    return 0;
}