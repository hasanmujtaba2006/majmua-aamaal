#include<stdio.h>
#include<stdbool.h>

int main(){
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&a[i]);
    }

    printf("Original Array : ");

    for (int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

    bool flag = false;

    for (int i=0,j=n-1;i<j;i++,j--){
        if (a[i]==a[j]){
            flag = true;
        }

        else{
            flag = false;
        }
    }

    if (flag==true){
        printf("\nPalindrome...");
    }
    else if (flag==false){
        printf("\nNot Palindrome...");
    }

    return 0;
}