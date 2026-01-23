#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    printf("Enter a string : ");
    scanf("%[^\n]s",str);

    int sum=0,i=0;

    while(str[i]!='\0'){
        sum++;
        i++;
    }

    for(int j=0,k=sum-1;j<=k;j++,k--){
        int temp=str[j];
        str[j]=str[k];
        str[k]=temp;
    }

    puts(str);
    return 0;
}