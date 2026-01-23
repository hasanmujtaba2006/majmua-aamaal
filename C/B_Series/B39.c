#include<stdio.h>

int main(){
    int n;
    printf("Enter number of term : ");
    scanf("%d",&n);

    int s = 0,sum = 0;

    for (int i=1;i<=n;i++){
        s += 1;
        if (s%2 != 0){
            sum += s;
        }

        if (s%2 == 0){
            sum -= s;
        }
    }

    printf("The sum of terms : %d",sum);

    return 0;
}