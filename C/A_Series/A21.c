#include<stdio.h>

int main(){
    int x;
    printf("Enter x-coordinate : ");
    scanf("%d",&x);

    int y;
    printf("Enter y-coordinate : ");
    scanf("%d",&y);

    if (x!=0 && y==0){
        printf("(%d,%d) lies on x-axis...",x,y);
    }

    else if (x==0 && y!=0){
        printf("(%d,%d) lies on y-axis...",x,y);
    }

    else if (x==0 && y==0){
        printf("(%d,%d) lies on origin...",x,y);
    }

    return 0;
}