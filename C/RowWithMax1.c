#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d", &n);

    int m;
    printf("Enter number of columns : ");
    scanf("%d", &m);

    int a[n][m];

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter Element : ");
            scanf("%d", &a[i][j]);
        }
    }

    int Maxcount = -1; // start with -1 to ensure first row is always considered
    int ri = -1;        // to track the row index

    // Find row with maximum number of 1s
    for (int k = 0; k < n; k++) {
        int count = 0;
        for (int l = 0; l < m; l++) {
            if (a[k][l] == 1) {
                count++;
            }
        }
        if (count > Maxcount) {
            Maxcount = count;
            ri = k;
        }
    }

    // Print the matrix
    printf("\nMatrix:\n");
    for (int c = 0; c < n; c++) {
        for (int b = 0; b < m; b++) {
            printf("%d ", a[c][b]);
        }
        printf("\n"); // fixed missing semicolon
    }

    if (ri != -1) {
        printf("Row %d has the maximum number of 1s: %d\n", ri, Maxcount);
    } else {
        printf("No 1s found in the matrix.\n");
    }

    return 0;
}
