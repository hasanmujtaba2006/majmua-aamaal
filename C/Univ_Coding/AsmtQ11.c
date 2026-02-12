#include<stdio.h>

void Func(){
    printf("Hello Hasan\n");
}

int main(){
    void (*ptr)();
    ptr = Func;
    ptr();
    return 0;
}