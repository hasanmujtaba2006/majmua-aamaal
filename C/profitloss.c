#include <stdio.h>
int main(){
    int cp;
    printf("Enter Cost Price : ");
    scanf("%d",&cp);
    int sp;
    printf("Enter Selling Price : ");
    scanf("%d",&sp);
    if (sp>cp){
        printf("You have made profit..\n");
        int p;
        p = sp-cp;
        printf("You have made profit of %d /-",p);

    }

    if (cp = sp){
        printf("You have neither loss nor profit...");

    }
    
    else {
        printf("You have made loss...\n");
        int l;
        l = cp-sp;
        printf("You have made loss of %d /-",l);


    }
    return 0;
}