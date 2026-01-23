#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

    int min= a[0];

    for (int j=0;j<=(n-1);j++){
        if (a[j]<min){
            min = a[j];
        }
    }
    printf("The minimum element : %d",min);
    return 0;
}