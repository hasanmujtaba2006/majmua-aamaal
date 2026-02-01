#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Pointer to an array of 5 integers
    int (*ptr)[5]; 
    
    ptr = &arr; 

    printf("Address of array: %p\n", ptr);
    
    // Accessing array elements using the pointer to array
    // (*ptr) gives the array itself, (*ptr)[i] gives the element
    printf("First element: %d\n", (*ptr)[0]);
    printf("Second element: %d\n", (*ptr)[1]);

    return 0;
}