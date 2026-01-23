#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    int a[n][m],maxSum=INT_MIN,ri;

    for (int k=0;k<n;k++){
        for (int l=0;l<m;l++){
            printf("\nEnter Element : ");
            scanf("%d",&a[k][l]);
        }
    }

    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=0;j<m;j++){
            sum+=a[i][j];
            if (maxSum<sum){
                maxSum=sum;
                ri=i;
            }
        }
    }
    printf("%d is max sum of row no. %d...",maxSum,ri);
    return 0;
}