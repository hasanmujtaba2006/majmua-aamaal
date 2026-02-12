#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr,n,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    ptr = (int *)calloc(n,sizeof(int));
    if (ptr==NULL){
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter %d integers : \n",n);
    for (i=0;i<n;i++){
        printf("\nEnter element %d : ",i+1);
        scanf("%d",&ptr[i]);
    }

    printf("Entered elements are : \n");
    for (i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }
    free(ptr);
    return 0;
}