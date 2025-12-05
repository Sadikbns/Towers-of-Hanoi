
#include <stdio.h>
#include "hanoi.h"

void hanoi_recursive(int n, char a, char c, char b) {
    if (n == 0) {
        return;
    }
    hanoi_recursive(n - 1, a, b, c);
    // printf("Move disk %d from %c to %c\n", n, a, c); its in comment to not affect the execution time
    hanoi_recursive(n - 1, b, c, a);
}
