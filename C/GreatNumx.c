#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("Enter element '%d' : ",i+1);
        scanf("%d",&a[i]);
    }

    int m,count=0;
    printf("Enter a number : ");
    scanf("%d",&m);

    for (int j=0;j<=(n-1);j++){
        if (a[j]>m){
            count++;
        }
    }
    printf("The number of elements greater then %d are %d..",m,count);
    return 0;
}