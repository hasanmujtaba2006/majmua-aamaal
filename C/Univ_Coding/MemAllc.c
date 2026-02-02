#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p,i,n,m;
    printf("Enter the value of n :- ");
    scanf("%d",&n);

    p = (int*)calloc(n,(sizeof(int)));

    for (i=0;i<n;i++){
        printf("\nEnter %dth element :- ",i+1);
        scanf("%d",&p[i]);
    }
    printf("Memory Allocated,Values are :- ");
    for (i=0;i<n;i++){
        printf("p[%d]=%d\n",i,p[i]);
    }

    printf("Enter the value of m :- ");
    scanf("%d",&m);

    p = (int*)realloc(p,m*(sizeof(int)));
    for (i=n;i<m+n;i++){
        printf("Enter %dth element : ",i+1);
        scanf("%d",&p[i]);
    }

    printf("Memory reallocated :- \n");
    for (i=0;i<m+n;i++){
        printf("p[%d]=%d\n",i,p[i]);
    }

    free(p);
    return 0;
}