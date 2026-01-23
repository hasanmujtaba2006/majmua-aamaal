#include<stdio.h>

int main(){
    int a[5] = {1,2,3,2,5};
    int dupele = 0;

    for (int i=0;i<5;i++){
        for (int j=i+1;j<5;j++){
            if (a[i]==a[j]){
                dupele = a[i];
            }
        }
    }

    printf("The duplicate element : %d",dupele);
    return 0;
}