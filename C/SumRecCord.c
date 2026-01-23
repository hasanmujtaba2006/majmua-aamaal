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
            printf("\nEnter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    int l1;
    printf("Enter first x-coordinate : ");
    scanf("%d",&l1);

    int r1;
    printf("Enter first y-coordinate : ");
    scanf("%d",&r1);

    int l2;
    printf("Enter second x-coordinate : ");
    scanf("%d",&l2);

    int r2;
    printf("Enter second y-coordinate : ");
    scanf("%d",&r2);

    int sum=0;

    for (int k=l1;k<=l2;k++){
        for (int l=r1;l<=r2;l++){
            sum+=a[k][l];
        }
    }
    printf("The sum of given rectangle : %d",sum);
    return 0;
}