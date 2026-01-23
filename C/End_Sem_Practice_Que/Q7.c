#include<stdio.h>
#include<string.h>

int main(){
    char str[12] = {'H','a','s','a','n','M','u','j','t','a','b','a'};

    int count=0;
    for (int i=0;i<12;i++){
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            count=count+1;
        }
    }

    printf("The total number of vowels in this string is %d ..",count);
    return 0;
}