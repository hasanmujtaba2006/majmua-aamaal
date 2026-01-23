#include<stdio.h>

int main(){
    int target;
    printf("Enter a target sum : ");
    scanf("%d",&target);

    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int ele1=0,ele2=0,a[n];

    for (int i=0,j=n-1;i<j;i++,j--){
        if (a[i]+a[j]==target){
            ele1=a[i];
            ele2=a[j];
            break;
        }

        else if (a[i]+a[j]>target){
            j--;
        }

        else if (a[i]+a[j]<target){
            i++;
        }
    }
    printf("The number whose sum is '%d' are (%d,%d)",target.ele1.ele2);
    return 0;
}