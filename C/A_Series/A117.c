#include<stdio.h>

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    int l1;
    printf("Enter index 1 of row : ");
    scanf("%d",&l1);

    int r1;
    printf("Enter index 1 of column : ");
    scanf("%d",&r1);

    int l2;
    printf("Enter index 2 of row : ");
    scanf("%d",&l2);

    int r2;
    printf("Enter index 2 of column : ");
    scanf("%d",&r2);

    int a[n][m];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("Enter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    int sum = 0;

    for (int i=l1;i<l2;i++){
        for (int j=r1;j<r2;j++){
            sum +=a[i][j];
        }
    }

    printf("The sum of element inside given range : %d",sum);

    return 0;
}