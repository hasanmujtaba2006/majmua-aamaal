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

    for (int j=0;j<=(n-1);j++){
        if (j%2!=0){
            a[j]=a[j]*2;
        }
        else{
            a[j]=a[j]+10;
        }
    }

    for (int k=0;k<=(n-1);k++){
        printf("%d ",a[k]);
    }
    return 0;
}