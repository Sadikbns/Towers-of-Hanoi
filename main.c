#include <stdio.h>
#include <time.h>
#include "hanoi.h"

int main() {
    int n, choix;
    int i;
    clock_t startTime, endTime;
    double seconds;

    printf("enter n: ");
    scanf("%d", &n);

    printf("choose the methode:\n");
    printf("1 - Recursive\n");
    printf("2 - Iterative\n");
    scanf("%d", &choix);

    printf("\nNumber of disks | Execution time (seconds)\n");
    printf("------------------------------------------\n");

    for (i = 1; i <= n; i++) {
//on cree une clock et on la lance pour chaque debut d'iteration
        startTime = clock();

        if (choix == 1) {
            hanoi_recursive(i, 'a', 'c', 'b');
        }
        else if (choix == 2) {
            hanoi_iterative(i, 'a', 'c', 'b');
        }
        else {
            printf("Invalid choice.\n");
            return 1;
        }

//on arrete la clock a la fin
        endTime = clock();

        //on calcule le temps d'execution
        seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        printf("      %2d        |     %f\n", i, seconds);
    }

    return 0;
}
