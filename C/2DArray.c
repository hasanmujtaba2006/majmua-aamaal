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
            printf("\nEnter Elements : ");
            scanf("%d",&a[i][j]);
        }
    }

    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }
    return 0;
}