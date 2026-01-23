#include<stdio.h>

int main(){
    int x1,x2,x3,y1,y2,y3;

    printf("Enter coordinate x1 : ");
    scanf("%d",&x1);

    printf("Enter coordinate y1 : ");
    scanf("%d",&y1);

    printf("Enter coordinate x2 : ");
    scanf("%d",&x2);

    printf("Enter coordinate y2 : ");
    scanf("%d",&y2);

    printf("Enter coordinate x3 : ");
    scanf("%d",&x3);

    printf("Enter coordinate y3 : ");
    scanf("%d",&y3);

    float m1,m2;
    m1 = (y2-y1)/(x2-x1);
    m2 = (y3-y2)/(x3-x2);

    if (m1==m2){
        printf("(%d,%d),(%d,%d) and (%d,%d) represents a straight line ..",x1,y1,x2,y2,x3,y3);
    }

    else{
        printf("These coordinates does not represent a straight line ..");
    }

    return 0;
}