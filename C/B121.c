#include<stdio.h>

int main(){
    int m;
    printf("Enter number of rows : ");
    scanf("%d",&m);

    int n;
    printf("Enter number of columns : ");
    scanf("%d",&n);

    int a[m][n];

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("Enter Element a[%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Matrix : \n");

    for (int k=0;k<m;k++){
        for (int l=0;l<n;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }

    for (int x=0;x<m;x++){
        for (int y=x+1;y<n;y++){
            int fake = a[x][y];
            a[x][y] = a[y][x];
            a[y][x] = fake;
        }
    }

    printf("Transpose of Matrix : \n");

    for (int k=0;k<m;k++){
        for (int l=0;l<n;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }

    return 0;
}