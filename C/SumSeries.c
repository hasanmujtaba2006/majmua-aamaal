#include<stdio.h>

int main() {
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    int s = 0,series = 0;
    for ( int i=1; i<=n;i++) {
        s =s+1;
        if ( s%2!=0){
            series = series + s;

        }

        else if ( s%2==0) {
            series = series - s;

        }

    } 
    printf("The sum of series : %d",series);
    return 0;  
}