#include <stdio.h>

int main() {
    int i, temp, l, s;

    for (i = 1; i <= 500; i++) {
        temp = i;    // Store original number
        s = 0;

        while (temp > 0) {
            l = temp % 10;
            temp = temp / 10;
            s = s + (l * l * l);
        }

        if (s == i) {
            printf("%d ", i);
        }
    }

    return 0;
}
