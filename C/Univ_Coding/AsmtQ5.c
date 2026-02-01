#include <stdio.h>

int main() {
    // Pointer to a string literal
    char *strPtr = "Hello World";
    
    printf("Full string: %s\n", strPtr);

    printf("Printing character by character:\n");
    // Iterate through string until null terminator '\0' is hit
    while (*strPtr != '\0') {
        printf("%c ", *strPtr);
        strPtr++; // Move to next character
    }
    printf("\n");

    return 0;
}