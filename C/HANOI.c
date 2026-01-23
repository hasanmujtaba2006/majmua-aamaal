#include <stdio.h>

void HANOI(int n,char s,char h,char d){
    if (n==0){
        return;
    }
    HANOI(n-1,s,d,h);
    printf("%c --> %c\n",s,d);
    HANOI(n-1,h,s,d);
    return;
}

int main(){
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);

    HANOI(n,'A','B','C');
    return 0;
}