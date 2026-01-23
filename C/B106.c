#include<stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element [%d] : ",i+1);
        scanf("%d",&a[i]);
    }

    int s = 0;
    for (int i=0,j=n-1;i<n,j>=0;i++,j--){
        if (a[i]==a[j]){
            s = 1;
        }

        if (a[i]!=a[j]){
            s = 0;
        }
    }

    if (s==1){
        printf("Palindrome..");
    }

    if (s==0){
        printf("Not Palindrome..");
    }

    return 0;
}