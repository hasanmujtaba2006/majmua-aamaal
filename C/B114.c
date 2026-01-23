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
            printf("Enter Element a[%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter Element b[%d][%d] : ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            c[k][l] = a[k][l] + b[k][l];
        }
    }

    printf("The sum of both matrices : \n");

    for (int s=0;s<n;s++){
        for (int t=0;t<m;t++){
            printf("%d ",c[s][t]);
        }
        printf("\n");
    }

    return 0;
}