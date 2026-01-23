#include<stdio.h>
#include<stdbool.h>

int main(){
    int a[5] = {1,2,3,3,2};
    int unqele=0;

    for (int i=0;i<5;i++){
        bool flag = false;
        for (int j=i+1;j<5;j++){
            if (a[i]==a[j]){
                flag = true;
            }
        }
        if (flag==false){
            printf("\nThe Unique Element : %d",a[i]);
            break;
        }
    }

    return 0;
}