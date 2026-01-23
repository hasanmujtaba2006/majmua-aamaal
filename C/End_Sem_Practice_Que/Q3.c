#include <stdio.h>
#include <string.h>

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    int isPal = 1;  

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            isPal = 0;
            break;
        }
    }

    if (isPal == 1)
        printf("Palindrome..");
    else
        printf("Not a palindrome..");

    return 0;
}
