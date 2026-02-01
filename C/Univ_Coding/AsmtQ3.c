#include <stdio.h>

int main() {
    int var = 3000;
    int *ptr;
    int **pptr; // Pointer to pointer declaration

    ptr = &var;    // ptr holds address of var
    pptr = &ptr;   // pptr holds address of ptr

    printf("Value of var: %d\n", var);
    printf("Value available at *ptr: %d\n", *ptr);
    printf("Value available at **pptr: %d\n", **pptr);

    return 0;
}