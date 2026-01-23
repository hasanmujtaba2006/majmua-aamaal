#include <stdio.h>

int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int a[size];
    for (int i=0;i<=(size-1);i++){
        printf("\nEnter element number %d : ",i+1);
        scanf("%d",&a[i]);
    }

    int sum=0;
    for (int j=0;j<=(size-1);j++){
        sum = sum+a[j];
    }
    printf("The sum of elements of array : %d",sum);
    return 0;
}