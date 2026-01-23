#include<stdio.h>

int main(){
    int len, bdth;
    
    printf("Enter length of a rectangle : ");
    scanf("%d",&len);

    printf("Enter breadth of a rectangle : ");
    scanf("%d",&bdth);

    int area,prm;

    area = len*bdth;
    prm = 2*(len+bdth);

    if (area > prm){
        printf("Yes, Area is greater than perimeter..");
    }

    if (area==prm){
        printf("Area is equal to perimeter..");
    }

    else{
        printf("No, Area is less than perimeter..");
    }

    return 0;
}