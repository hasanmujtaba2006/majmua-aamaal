#include <stdio.h>

int main() {
    int num = 100;
    int *ptr;  // Declaration of single-level pointer

    ptr = &num; // Storing the address of num in ptr

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Value stored in ptr (Address of num): %p\n", ptr);
    printf("Value pointed to by ptr: %d\n", *ptr); // Dereferencing

    return 0;
}