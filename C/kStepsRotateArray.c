#include <stdio.h>

void reverse(int arr[],int si,int ei){
    for (int i=si,j=ei;i<=j;i++,j--){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return;
}

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<=(n-1);i++){
        printf("\nEnter Element '%d' : ",i+1);
        scanf("%d",&a[i]);
    }

    int k;
    printf("Enter number od steps : ");
    scanf("%d",&k);

    k=k%n;

    reverse(a,0,n-1);
    reverse(a,0,k-1);
    reverse(a,k,n-1);

    for (int j=0;j<=(n-1);j++){
        printf("%d ",a[j]);
    }
    return 0;
}