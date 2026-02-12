#include<stdio.h>

int Func(int *a,int *b){
    *a+=10;
    *b+=5;
    printf("during function a=%d,b=%d\n",*a,*b);
    return 0;
}

int main(){
    int a=10,b=15;
    printf("before function a=%d,b=%d\n",a,b);
    Func(&a,&b);
    printf("after function a=%d,b=%d\n",a,b);
    return 0;
}