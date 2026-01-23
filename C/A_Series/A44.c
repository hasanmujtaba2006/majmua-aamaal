#include<stdio.h>

int main(){
    int a=65;

    for (int i=1;i<=26;i++){
        printf("%d --> %c\n",a,(char)a);
        a+=1;
    }

    return 0;
}