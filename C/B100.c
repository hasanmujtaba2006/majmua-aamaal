#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};

    int sumodd = 0,sumeven = 0;

    for (int i=0;i<5;i++){
        if (i%2==0){
            sumeven+=a[i];
        }

        if (i%2!=0){
            sumodd+=a[i];
        }
    }

    printf("The difference between sum of elements in even index and odd index : %d",sumeven-sumodd);

    return 0;
}