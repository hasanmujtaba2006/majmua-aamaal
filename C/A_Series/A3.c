#include<stdio.h>

int main(){
    int phy;
    printf("Enter marks of Physics : ");
    scanf("%d",&phy);

    int chem;
    printf("Enter marks of Chemistry : ");
    scanf("%d",&chem);

    int math;
    printf("Enter marks of Mathematics : ");
    scanf("%d",&math);

    int eng;
    printf("Enter marks of English : ");
    scanf("%d",&eng);

    int com;
    printf("Enter marks of Computer : ");
    scanf("%d",&com);

    float avg = (phy+chem+math+eng+com)/5;

    printf("The average marks : %f",avg);
    return 0;
}