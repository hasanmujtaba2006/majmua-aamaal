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
            a[i][j] = 10;
        }
    }

    printf("The 2-D Array : \n");

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}