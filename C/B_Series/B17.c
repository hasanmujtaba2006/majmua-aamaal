#include<stdio.h>

int main(){
    int hasan,husain,mohsin;
    
    printf("Enter age of Hasan : ");
    scanf("%d",&hasan);

    printf("Enter age of Husain : ");
    scanf("%d",&husain);

    printf("Enter age of Mohsin : ");
    scanf("%d",&mohsin);

    if (hasan<husain && hasan<mohsin){
        printf("Hasan is youngest...");
    }

    if (husain<hasan && husain<mohsin){
        printf("Husain is youngest...");
    }

    if (mohsin<hasan && mohsin<husain){
        printf("Mohsin is youngest...");
    }

    return 0;
}