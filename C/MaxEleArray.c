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

    int max = a[0];

    for (int j=0;j<=(n-1);j++){
        if (a[j]>max){
            max = a[j];
        }
    }
    printf("The max element : %d",max);
    return 0;
}