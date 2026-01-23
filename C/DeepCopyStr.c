#include<stdio.h>
#include<string.h>

int main(){
    char str1[]="Hasan Mujtaba";

    int size=0,i=0;
    while(str1[i]!='\0'){
        size++;
        i++;
    }

    char str2[size];

    for (int j=0;j<=(size-1);j++){
        str2[j] = str1[j];
    }

    puts(str2);
    return 0;
}