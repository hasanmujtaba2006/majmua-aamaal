#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        a[i]=i+1;
    }
    int nsum = 0;
    for (int j=0;j<=n;j++){
        nsum+=j;
    }

    int sum=0;

    for (int k=0;k<=(n-1);k++){
        sum+=a[k];
    }

    printf("The number missing is %d...",nsum-sum);
    return 0;
}