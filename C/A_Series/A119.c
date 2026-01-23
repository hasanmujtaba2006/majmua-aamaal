#include<stdio.h>

int main(){
    int a[3][3] = {{1,0,1},{1,0,0},{0,0,0}};

    int maxsum = -1,idx=0;

    for (int i=0;i<3;i++){
        int sum = 0;
        for (int j=0;j<3;j++){
            sum+=a[i][j];
        }  
        if (sum>maxsum){
            maxsum = sum;
            idx = i;
        }
    }

    printf("The index of row which have maximum '1' : %d",idx);

    return 0;
}