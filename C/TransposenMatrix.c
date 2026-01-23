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

    printf("Matrix:\n");

    for (int k=0;k<n;k++){
        for (int l=0;l<n;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }

    for (int c=0;c<n;c++){
        for (int b=0;b<c;b++){
            int temp = a[c][b];
            a[c][b] = a[b][c];
            a[b][c] = temp;
        }
    }

    printf("Transpose Matrix:\n");

    for (int h=0;h<n;h++){
        for (int m=0;m<n;m++){
            printf("%d ",a[h][m]);
        }
        printf("\n");
    }
    return 0;
}