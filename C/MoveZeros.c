#include<stdio.h>

int main(){
    int a[9]={5,0,2,0,0,4,1,3,0};
    int n=9;

    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (a[j]==0){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
    return 0;
}