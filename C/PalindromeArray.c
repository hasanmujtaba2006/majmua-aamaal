#include <stdio.h>

void palindrome(int arr[], int n) {
    int isPalindrome = 1;

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("Palindrome...\n");
    } else {
        printf("Not Palindrome...\n");
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Element '%d': ", i + 1);
        scanf("%d", &a[i]);
    }

    palindrome(a, n);

    return 0;
}
