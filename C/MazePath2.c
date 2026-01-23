#include <stdio.h>

int maze(int n,int m){
    int rw=0,dw=0;
    if(n==1 && m==1){
        return 1;
    }
    if(n==1){
        rw+=maze(n,m-1);
    }
    if(m==1){
        dw+=maze(n-1,m);
    }
    else{
        rw+=maze(n,m-1);
        dw+=maze(n-1,m);
    }
    int tw=rw+dw;
    return tw;
}

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d",&m);

    printf("Ways : %d",maze(n,m));
    return 0;
}