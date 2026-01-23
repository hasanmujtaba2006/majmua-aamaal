#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d", &n);

    int nsp = 0, nst = n;

    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= nsp; j++) {
            printf(" ");
        }

        // Print stars
        for (int k = 1; k <= nst; k++) {
            printf("*");
        }

        // Move to next line
        printf("\n");

        // Update counters
        nsp++;
        nst--;
    }

    return 0;
}
