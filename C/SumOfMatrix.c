#include <stdio.h>

int main(){
    int a[3][3]={{2,3,1},{6,9,7},{8,4,3}};
    int b[3][3]={{1,2,5},{6,3,1},{2,2,5}};
    int c[3][3];

    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    for (int k=0;k<3;k++){
        for (int l=0;l<3;l++){
            printf("%d ",c[k][l]);
        }
        printf("\n");
    }
    return 0;
}