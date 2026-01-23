#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int nsum=0,a[n],sum=0;

    for (int i=1;i<=n;i++){
        nsum+=i;
    }

    for (int j=0;j<(n+1);j++){
        printf("Enter a element less than '%d' : ",n);
        scanf("%d",&a[j]);
    }

    for (int k=0;k<(n+1);k++){
        sum+=a[k];
    }

    printf("The duplicate element in the array is %d..",sum-nsum);
    return 0;
}