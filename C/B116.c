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

    int max = a[0][0],min = a[0][0];

    for (int s=0;s<m;s++){
        for (int t=0;t<n;t++){
            if (a[s][t]>max){
                max = a[s][t];
            }

            if (a[s][t]<min){
                min = a[s][t];
            }
        }
    }

    printf("The maximum element [%d] and minimum element [%d] ..",max,min);

    return 0;
}