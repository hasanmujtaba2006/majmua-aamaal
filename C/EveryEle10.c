#include <stdio.h>

int main(){
    int a[5][5];

    for(int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            a[i][j]=10;
        }
    }

    for (int k=0;k<5;k++){
        for (int l=0;l<5;l++){
            printf("%d ",a[k][l]);
        }
        printf("\n");
    }
    return 0;
}