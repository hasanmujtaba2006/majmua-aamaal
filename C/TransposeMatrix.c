#include <stdio.h>

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
            printf("Enter element : ");
            scanf("%d",&a[i][j]);
        }
    }
    printf("Transpose of Matrix : \n ");
    for (int k=0;k<m;k++){
        for (int l=0;l<n;l++){
            printf("%d ",a[l][k]);
        }
        printf("\n");
    }
    return 0;
} 