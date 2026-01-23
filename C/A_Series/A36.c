#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int evensum = 0,ld = 0;

    while (n>0){
        ld = n%10;
        n = n/10;
        if (ld%2==0){
            evensum += ld; 
        }
    }

    printf("The sum of even digits : %d",evensum);

    return 0;
}