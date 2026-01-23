#include <stdio.h>

int main(){
    int n;
    printf("Enter size of Array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("Enter element '%d' : ",i+1);
        scanf("%d",&a[i]);
    }

    int x;
    printf("Enter a number to search : ");
    scanf("%d",&x);

    for (int j=0;j<=(n-1);j++){
        if (a[j]==x){
            printf("%d is found in the array and its index is %d",x,j);
            break;
        }
        else if (a[j]!=x){
            printf("Not found....");
        }
    }
    return 0;
} 