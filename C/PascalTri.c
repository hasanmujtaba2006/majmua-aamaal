#include <stdio.h>

int combination(int n,int r){
    int nfact = 1;

    for (int k=1;k<=n;k++){
        nfact=nfact*k;
    }

    int rfact = 1;

    for (int l=1;l<=r;l++){
        rfact=rfact*l;
    }

    int nrfact = 1;

    for (int m=1;m<=(n-r);m++){
        nrfact=nrfact*m;
    }
    int comb=nfact/(rfact*nrfact);
    return comb;
}

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    for (int i=0;i<=n;i++){
        for (int j=0;j<=i;j++){
            int l = combination(i,j);
            printf("%d ",l);
        }
        printf("\n");
    }
    return 0;
} 

    