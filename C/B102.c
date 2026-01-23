#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    int x,count=0;
    printf("Enter number whose triplet : ");
    scanf("%d",&x);

    for (int i=0;i<5;i++){
        for (int j=i+1;j<5;j++){
            for (int k=j+1;k<5;k++){
                if ((a[i]+a[j]+a[k])==x){
                    count++;
                }
            }
        }
    }

    printf("The number of triplet are %d whose sum is equal to x ..",count,x);

    return 0;
}