#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Points to the first element (10)

    printf("Original position (*ptr): %d\n", *ptr);

    ptr++; // Move to next integer (adds 4 bytes to address)
    printf("After ptr++ (*ptr): %d\n", *ptr);

    ptr = ptr + 2; // Jump forward 2 positions
    printf("After ptr + 2 (*ptr): %d\n", *ptr);

    ptr--; // Move back one position
    printf("After ptr-- (*ptr): %d\n", *ptr);

    return 0;
}