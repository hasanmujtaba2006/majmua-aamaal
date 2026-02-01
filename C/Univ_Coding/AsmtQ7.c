#include <stdio.h>

int main() {
    int i = 10;
    float f = 5.5;
    char c = 'Z';

    void *ptr; // Generic pointer declaration

    // Pointing to Integer
    ptr = &i;
    // We must cast (int*) before dereferencing
    printf("Integer value: %d\n", *(int*)ptr);

    // Pointing to Float
    ptr = &f;
    printf("Float value: %.1f\n", *(float*)ptr);

    // Pointing to Char
    ptr = &c;
    printf("Char value: %c\n", *(char*)ptr);

    return 0;
}