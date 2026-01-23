#include<stdio.h>

int main(){
    int cp;
    printf("Enter Cost Price : ");
    scanf("%d",&cp);

    int sp;
    printf("Enter Selling Price : ");
    scanf("%d",&sp);

    if (sp>cp){
        int profit = sp-cp;
        printf("You have made profit of %d",profit);
    }

    else if (sp==cp){
        printf("Neither Profit Nor Loss");
    }

    else{
        int loss = cp-sp;
        printf("You have made Loss of %d",loss);
    }

    return 0;
}