#include <stdio.h>

int main(){
    int hasan;
    printf("Enter age of Hasan : ");
    scanf("%d",&hasan);

    int husain;
    printf("Enter age of Husain : ");
    scanf("%d",&husain);

    int mohsin;
    printf("Enter age of Mohsin : ");
    scanf("%d",&mohsin);

    if (hasan<husain){
        if (hasan<mohsin){
            printf("Hasan is youngest....");

        }

        else{
            printf("Mohsin is youngest....");

        }

    }

    else {
        if (husain<mohsin){
            printf("Husain is youngest....");

        }

        else {
            printf("Mohsin is youngest....");

        }
    }
    return 0;
    
}