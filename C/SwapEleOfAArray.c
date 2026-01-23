#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int l=0;l<=(n-1);l++){
        printf("Enter element '%d' : ",l+1);
        scanf("%d",&a[l]);
    }

    int i = 0, j = n - 1;
    while (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    for (int k=0;k<=(n-1);k++){
        printf("%d ",a[k]);
    }
    return 0;
}