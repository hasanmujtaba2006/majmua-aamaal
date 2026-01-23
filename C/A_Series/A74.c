#include<stdio.h>

int combination(int n,int r){
    int nfact = 1;
    for (int i=1;i<=n;i++){
        nfact = nfact*i;
    }

    int rfact = 1;
    for (int j=1;j<=r;j++){
        rfact = rfact*j;
    }

    int nrfact = 1;
    for (int k=1;k<=(n-r);k++){
        nrfact = nrfact*k;
    }

    int combination = nfact/(rfact*nrfact);

    return combination;
}

int permutation(int n,int r){
    int nfact = 1;
    for (int i=1;i<=n;i++){
        nfact = nfact*i;
    }

    int nrfact = 1;
    for (int j=1;j<=(n-r);j++){
        nrfact = nrfact*j;
    }

    int permutation = nfact/nrfact;

    return permutation;
}

int main(){
    int n;
    printf("Enter value of 'n' : ");
    scanf("%d",&n);

    int r;
    printf("Enter value of 'r' : ");
    scanf("%d",&r);

    printf("The Combination : %d\n",combination(n,r));
    printf("The Permutation : %d",permutation(n,r));

    return 0;
}