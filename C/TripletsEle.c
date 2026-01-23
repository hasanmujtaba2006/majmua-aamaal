#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("Enter Element '%d' : ",i+1);
        scanf("%d",&a[i]);
    }

    int count=0,m;
    printf("Enter a number : ");
    scanf("%d",&m);

    for (int j=0;j<=(n-1);j++){
        for (int k=j+1;k<=(n-1);k++){
            for (int l=k+1;l<=(n-1);l++){
                if (a[j]+a[k]+a[l]==m){
                    count++;
                }
            }
        }
    }
    printf("The sum of number of triplets of elements is equal %d are %d",m,count);
    return 0;
}