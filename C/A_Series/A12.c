#include<stdio.h>

int main(){
    int l;
    printf("Enter Length of rectangle : ");
    scanf("%d",&l);

    int b;
    printf("Enter Breadth of rectangle : ");
    scanf("%d",&b);

    int area = l*b;

    int perimeter = 2*(l+b);

    if (area>perimeter){
        printf("Yooo! Area of rectangle is greater then perimeter of rectangle...");
    }

    else{
        printf("Nope! Perimeter is greater than area...");
    }

    return 0;
}