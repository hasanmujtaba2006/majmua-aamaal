#include <stdio.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];
    int b[n];

    for (int i=0;i<=(n-1);i++){
        printf("Enter Element '%d' : ",i+1);
        scanf("%d",&a[i]);
    }

    for (int j=0;j<=(n-1);j++){
        b[j]=a[n-1-j];
    }

    for (int k=0;k<=(n-1);k++){
        printf("%d ",b[k]);
    }
    return 0;
}