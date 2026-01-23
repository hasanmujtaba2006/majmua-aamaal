#include<stdio.h>
#include<string.h>
int main(){
    char a[] = "Hasan is a good boy";

    int size = 0,i=0;
    while(a[i]!='\o'){
        size++;
        i++;
    }

    for (int i=0,j=size-1;i<j;i++,j--){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    printf("The reversed string : ");
    puts(a);

    return 0;
}