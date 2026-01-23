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
            printf("Enter Element a[%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Matrix : \n");
    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int s=0;s<n;s++){
        for (int t=0;t<m;t++){
            sum+=a[s][t];
        }
    }
    printf("The sum of elements of matrix : %d",sum);
    return 0;
}