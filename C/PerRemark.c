#include <stdio.h>
int main() {
    float per;
    printf("Enter your percentage : ");
    scanf("%f",&per);

    if ( per>=90 && per<=100) {
        printf("Excellent....");

    }

    else if ( per>=80 && per<90) {
        printf("Very Good....");

    }

    else if ( per>=70 && per<80) {
        printf("Good....");

    }

    else if ( per>=60 && per<70) {
        printf("Can do better....");

    }

    else if ( per>=50 && per<60) {
        printf("Average....");

    }

    else if ( per>=40 && per<50) {
        printf("Below Average....");

    }

    else if ( per<40) {
        printf("Fail....");

    }
    return 0;
    
}