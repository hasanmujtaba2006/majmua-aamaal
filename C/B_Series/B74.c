#include<stdio.h>

int main(){
    int n;
    printf("Enter value of n : ");
    scanf("%d",&n);

    int r;
    printf("Enter value of r : ");
    scanf("%d",&r);

    //Calculating n factorial//
    int nfact = 1;
    for (int i=1;i<=n;i++){
        nfact = nfact*i;
    }

    //Calculating r factorial//
    int rfact = 1;
    for (int i=1;i<=r;i++){
        rfact = rfact*i;
    }

    //Calculating (n-r) factorial//
    int nrfact = 1;
    for (int i=1;i<=(n-r);i++){
        nrfact = nrfact*i;
    }

    //Calculating combination//
    int comb = nfact/(rfact*nrfact);

    //Calculating permutation//
    int perm = nfact/nrfact;

    printf("The combination on the value of n=%d,r=%d is %d and permutation is %d ..",n,r,comb,perm);

    return 0;
}