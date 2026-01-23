#include <stdio.h>

int main() {
    int n;
    printf("Enter the term : ");
    scanf("%d",&n);

    int x=1,y=1,sum=1;

    if (n>=1){
        printf("%d ",x);
    }  
    
    if (n>=2){
        printf("%d ",y);
    }  

    for ( int i = 1; i<=(n-2); i++ ) {
        sum = x+y;
        printf("%d ",sum);
        x=y;
        y=sum;
    }
    return 0;
}