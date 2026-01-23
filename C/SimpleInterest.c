#include <stdio.h>
int main(){
    float p;
    printf("Enter Principal : ");
    scanf("%f",&p);
    float r;
    printf("Enter Rate : ");
    scanf("%f",&r);
    float t;
    printf("Enter Time : ");
    scanf("%f",&t);
    float SI = (p*r*t)/100;
    printf("Simple Interest : %f", SI);
    return 0;  
    
}