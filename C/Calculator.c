#include<stdio.h>

int main(){
    int a;
    printf("Enter 1st number : ");
    scanf("%d",&a);

    char ch;
    printf("\nEnter operation (+,-,*,/) : ");
    scanf("%c",&ch);

    int b;
    printf("\nEnter 2nd number : ");
    scanf("%d",&b);

    switch(ch){
        case '+':
        printf("%d",a+b);
        break;
        case '-':
        printf("%d",a-b);
        break;
        case '*':
        printf("%d",a*b);
        break;
        case '/':
        printf("%f",(float)a/b);
        break;
        default:
        printf("Invalid Operation...");
    }
    return 0;
}