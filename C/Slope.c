#include <stdio.h>

int main() {
    int x1,x2,x3,y1,y2,y3;
    printf("Enter 1st x-coordinate : ");
    scanf("%d",&x1);
    printf("Enter 1st y-coordinate : ");
    scanf("%d",&y1);
    printf("Enter 2nd x-coordinate : ");
    scanf("%d",&x2);
    printf("Enter 2nd y-coordinate : ");
    scanf("%d",&y2);
    printf("Enter 3rd x-coordinate : ");
    scanf("%d",&x3);
    printf("Enter 3rd y-coordinate : ");
    scanf("%d",&y3);

    float m1;
    m1 = (y2-y1)/(x2-x1);

    float m2;
    m2 = (y3-y2)/(x3-x2);

    if (m1==m2) {
        printf("All three coordinates falls on one straight line...");

    }

    else {
        printf("All three coordinates does'nt lie on one straight line...");

    }
     
}
