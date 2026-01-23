#include <stdio.h>
int main() {
    int x,y;
    printf("Enter Co-ordinates (x,y) : ");
    scanf("%d %d",&x,&y);

    if (x!=0 && y==0){
        printf("The co-ordinate (%d,%d) lies on x-axis",x,y);

    }

    else if (x==0 && y!=0){
        printf("The co-ordinate (%d,%d) lies on y-axis",x,y);

    }

    else if (x==0 && y==0){
        printf("The co-ordinate (%d,%d) lies on origin",x,y);

    }

    else {
        printf("The co-ordinate (%d,%d) lies on plane..",x,y);

    }

}