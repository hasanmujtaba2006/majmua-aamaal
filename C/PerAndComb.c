#include <stdio.h>

int combination(int n,int r){
    int fact_1=1;

    for (int i=1;i<=n;i++){
        fact_1= fact_1*i;
    }

    int fact_2=1;

    for (int j=1;j<=r;j++){
        fact_2 = fact_2*j;
    }

    int fact_3=1;

    for (int k=1;k<=(n-r);k++){
        fact_3 = fact_3*k;
    }

    int comb = fact_1/(fact_2*fact_3);

    return comb;
}


int permutation(int n,int r){
    int fact_1=1;

    for (int i=1;i<=n;i++){
        fact_1=fact_1*i;
    }

    int fact_2=1;

    for (int j=1;j<=(n-r);j++){
        fact_2=fact_2*j;
    }

    int perm = fact_1/fact_2;
    return perm;
}

int main (){
    int a;
    printf("Enter the value of n : ");
    scanf("%d",&a);

    int b;
    printf("Enter the value of r : ");
    scanf("%d",&b);

    if (b > a || a < 0 || b < 0) {
        printf("Invalid input. Ensure that 0 <= r <= n.\n");
    }

    int l = combination(a,b);

    int m = permutation(a,b);
    printf("The combination is %d\n",l);
    printf("The permutation is %d",m);
    return 0;

}