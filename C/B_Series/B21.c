#include<stdio.h>

int main(){
    int x,y;

    printf("Enter coordinate of x-axis : ");
    scanf("%d",&x);

    printf("Enter coordinate of y-axis : ");
    scanf("%d",&y);

    if (x!=0 && y==0){
        printf("(%d,%d) lies on x-axis ..",x,y);
    }

    if (x==0 && y!=0){
        printf("(%d,%d) lies on y-axis ..",x,y);
    }

    if (x==0 && y==0){
        printf("(%d,%d) lies on origin ..",x,y);
    }

    if (x!=0 && y!=0) {
        printf("(%d,%d) lies anywhere in the plane ..",x,y);
    }

    return 0;
}