#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int min = 0;

    for (int i=1;i<=2*n-1;i++){
        int a=i;
        for (int j=1;j<=2*n-1;j++){
            int b=j;
            if(i>n) a = 2*n-i;
            if(j>n) b = 2*n-j;
            if (a<b){
                printf("%d",a);
            }

            else {
                printf("%d",b);
            }
        }
        printf("\n");
    }
    return 0;
}