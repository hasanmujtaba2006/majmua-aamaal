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

    int maxsum = -1,idx=0;

    for (int i=0;i<n;i++){
        int sum = 0;
        for (int j=0;j<n;j++){
            sum+=a[i][j];
        }
        if (sum>maxsum){
            maxsum = sum;
            idx = i;
        }
    }

    printf("The index of row which have maximum sum : %d",idx);

    return 0;
   
}