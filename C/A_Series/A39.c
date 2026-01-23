#include<stdio.h>

int main(){
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    int a=1,sum=0;

    for (int i=1;i<=n;i++){
        if (i%2==0){
            sum = sum - i;
        }

        else if (i%2!=0){
            sum = sum + i;
        }
    }

    printf("The sum of the series is %d",sum);
    return 0;
}