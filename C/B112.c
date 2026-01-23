#include<stdio.h>

int main(){
    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    int a[2][m];

    for (int i=0;i<2;i++){
        for (int j=0;j<m;j++){
            printf("Enter Roll Number : ");
            scanf("%d",&a[0][j]);

            printf("Enter Marks : ");
            scanf("%d",&a[1][j]);
        }
    }

    printf("Roll Number | Marks\n");

    for (int i=0;i<2;i++){
        for (int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}