#include <stdio.h>

int maze(int cr,int cc,int er,int ec){
    int rightWays = 0;
    int downWays = 0;
    if (cr==er && cc==ec){
        return 1;
    }
    if (cr==er){
        rightWays = rightWays+maze(cr,cc+1,er,ec);
    }
    if (cc==ec){
        downWays = downWays+maze(cr+1,cc,er,ec);
    }
    if (cr<er && cc<ec){
        rightWays = rightWays+maze(cr,cc+1,er,ec);
        downWays = downWays+maze(cr+1,cc,er,ec);
    }
    int totalWay = rightWays+downWays;
    return totalWay;
}

int main(){
    int a;
    printf("Enter number of rows : ");
    scanf("%d",&a);

    int b;
    printf("Enter number of columns : ");
    scanf("%d",&b);

    printf("The number ways to reach : %d",maze(1,1,a,b));
    return 0;
}