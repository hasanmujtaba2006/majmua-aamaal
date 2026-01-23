#include<stdio.h>

int main(){
    int x1;
    printf("Enter 1st x-coordinate : ");
    scanf("%d",&x1);

    int y1;
    printf("Enter 1st y-coordinate : ");
    scanf("%d",&y1);

    int x2;
    printf("Enter 2nd x-coordinate : ");
    scanf("%d",&x2);

    int y2;
    printf("Enter 2nd y-coordinate : ");
    scanf("%d",&y2);

    int x3;
    printf("Enter 3rd x-coordinate : ");
    scanf("%d",&x3);

    int y3;
    printf("Enter 3rd y-coordinate : ");
    scanf("%d",&y3);

    int m1 = (y2-y1)/(x2-x1);
    int m2 = (y3-y2)/(x3-x2);

    if (m1==m2){
        printf("(%d,%d),(%d,%d) and (%d,%d) lies on a straight line...",x1,y1,x2,y2,x3,y3);
    }

    else{
        printf("(%d,%d),(%d,%d) and (%d,%d) not lies on a straight line...",x1,y1,x2,y2,x3,y3);
    }

    return 0;
}