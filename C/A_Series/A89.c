#include<stdio.h>

int maze(int cr,int cc,int er,int ec){
    int rw=0,dw=0;
    if (cr==er && cc==ec){
        return 1;
    }

    if (cr==er){
        rw+=maze(cr,cc+1,er,ec);
    }

    if (cc==ec){
        dw+=maze(cr+1,cc,er,ec);
    }

    if (cr<er && cc<ec){
        rw+=maze(cr,cc+1,er,ec);
        dw+=maze(cr+1,cc,er,ec);
    }

    return rw+dw;
}

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    printf("The total number of ways to reach end : %d",maze(1,1,n,m));
    return 0;
}