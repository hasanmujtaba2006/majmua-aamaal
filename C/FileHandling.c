#include<stdio.h>

int main(){
    FILE* ptr = fopen("Hasan.txt","w");
    char str[100] = "Hello World\nText has been replaced.";
    fputs(str,ptr);
    fclose(ptr);
    return 0;
}