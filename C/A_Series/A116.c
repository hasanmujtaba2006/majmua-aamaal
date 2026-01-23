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
            printf("Enter Element : ");
            scanf("%d",&a[i][j]);
        }
    }

    int max=a[0][0],min=a[0][0];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]<min){
                min = a[i][j];
            }

            else if (a[i][j]>max){
                max = a[i][j];
            }
        }
    }

    printf("The maximum element in matrix %d \nThe minimum element in matrix %d",max,min);
    return 0;
}