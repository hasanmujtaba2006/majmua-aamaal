#include<stdio.h>

int main(){
    int n;
    printf("Enter number of rows of matrix 1 : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns of matrix 1 & rows of matrix 2 : ");
    scanf("%d",&m);

    int o;
    printf("Enter number of columns of matrix 2 : ");
    scanf("%d",&o);

    int a[n][m],b[m][o],c[n][o];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter Element [%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Matrix 1:\n");

    for (int s=0;s<n;s++){
        for (int t=0;t<m;t++){
            printf("%d ",a[s][t]);
        }
        printf("\n");
    }

    for (int k=0;k<m;k++){
        for (int l=0;l<o;l++){
            printf("Enter Element [%d][%d] : ",k,l);
            scanf("%d",&b[k][l]);
        }
    }

    printf("Matrix 2:\n");

    for (int g=0;g<m;g++){
        for (int h=0;h<o;h++){
            printf("%d ",b[g][h]);
        }
        printf("\n");
    }

    int r=m;

    for (int u=0;u<n;u++){
        for (int v=0;v<o;v++){
            c[u][v]=0;
            for (int w=0;w<r;w++){
                c[u][v]+=a[u][w]*b[w][v];
            }
        }
    }

    printf("Multiplication Of Matrices:\n");

    for (int x=0;x<n;x++){
        for (int y=0;y<o;y++){
            printf("%d ",c[x][y]);
        }
        printf("\n");
    }
    return 0;
}