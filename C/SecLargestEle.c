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

    int max=a[0],smax=a[0];

    for (int j=0;j<=(n-1);j++){
        if (max<a[j]){
            max = a[j];
        }
    }

    for (int k=0;k<=(n-1);k++){
        if (a[k]!=max && smax<a[k]){
            smax = a[k];
        }
    }
    printf("The second greatest number : %d",smax);
    return 0;
}
