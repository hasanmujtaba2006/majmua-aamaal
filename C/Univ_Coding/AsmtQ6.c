#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    // CASE 1: Pointer to Constant
    // "Value is locked, Address is free"
    const int *ptr1 = &a; 
    
    // *ptr1 = 50;  // ERROR: Cannot modify the value
    ptr1 = &b;      // VALID: Can change the address it points to
    printf("Pointer to Constant points to value: %d\n", *ptr1);


    // CASE 2: Constant Pointer
    // "Address is locked, Value is free"
    int * const ptr2 = &a;
    
    *ptr2 = 50;     // VALID: Can modify the value
    // ptr2 = &b;   // ERROR: Cannot change the address
    printf("Constant Pointer value modified to: %d\n", *ptr2);

    return 0;
}