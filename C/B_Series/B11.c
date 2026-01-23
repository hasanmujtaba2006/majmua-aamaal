#include<stdio.h>

int main(){
    float sp,cp;
    printf("Enter Selling Price of item : $");
    scanf("%f",&sp);

    printf("Enter Cost Price of item : $");
    scanf("%f",&cp);

    if (sp>cp){
        float prof;
        prof = sp - cp;
        printf("You have made profit of $%.2f.. ",prof);
    }

    if (cp>sp){
        float loss;
        loss = cp - sp;
        printf("You have made loss of $%.2f..",loss);
    }

    if (sp==cp){
        printf("You have neither made loss nor profit..");
    }

    return 0;
}