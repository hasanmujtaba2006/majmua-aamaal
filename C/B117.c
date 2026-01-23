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

    int l1,l2,r1,r2;
    printf("Enter range l1 : ");
    scanf("%d",&l1);

    printf("Enter range l2 : ");
    scanf("%d",&l2);

    printf("Enter range r1 : ");
    scanf("%d",&r1);

    printf("Enter range r2 : ");
    scanf("%d",&r2);

    int sum = 0;
    for (int i=l1;i<=l2;i++){
        for (int j=r1;j<=r2;j++){
            sum+=a[i][j];
        }
    }

    printf("The sum of element of range from (%d,%d) to (%d,%d) is [%d]..",l1,r1,l2,r2,sum);

    return 0;
}