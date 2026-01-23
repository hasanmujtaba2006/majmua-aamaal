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

    int idx = 0,max = 0;
    for (int k=0;k<m;k++){
        int r_sum = 0;
        for (int l=0;l<n;l++){
            r_sum+=a[k][l];

            if (r_sum>max){
                max = r_sum;
                idx = k;
            }
        }
    }

    printf("The row number with maximum sum is [%d] ..",idx+1);

    return 0;    
}