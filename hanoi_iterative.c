#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// since we're not using recursion -that will save each state implicitly (handled by c language)-
// we are defining a task struct to hold the info of each task (moving disks)
// before moving to another task (moving other disks) 
typedef struct {
    int n;           // number of disks
    char source;     // source peg
    char dest;       // destination peg
    char aux;        // auxiliary peg
} Task;

void hanoi_iterative(int n, char start, char end, char aux) {
    // Create a stack - using array
    Task *stack = malloc(sizeof(Task) * 1000);
    int top = -1;
    
    // Push the initial problem onto the stack
    stack[++top] = (Task){n, start, end, aux};
    
    while (top >= 0) {
        Task current = stack[top--];  // Pop from stack
        
        if (current.n == 1) {
            // we are not printing moving steps for calculating purposes
            // printf("moving 1 disk from %c to %c\n", current.source, current.dest);
            continue; // so just continue without printing
        } else {
            // Push three tasks in REVERSE order
            stack[++top] = (Task){current.n - 1, current.aux, current.dest, current.source};
            stack[++top] = (Task){1, current.source, current.dest, current.aux};
            stack[++top] = (Task){current.n - 1, current.source, current.aux, current.dest};
        }
    }
    
    free(stack);
}

// this will the same main function used to test recursive version of hanoi
// (calculating time required to move 1 to n disks)
int main() {
    int n;
    int i;
    clock_t startTime;
    clock_t endTime;
    double seconds;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nNumber of disks | Execution time (seconds)\n");
    printf("------------------------------------------\n");

    for (i = 1; i <= n; i++) {

        // on démarre la clock
        startTime = clock();

        hanoi_iterative(i, 'A', 'C', 'B');

        // on stop la clock
        endTime = clock();

        // on calcule le temps total
        seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        printf("      %2d        |     %f\n", i, seconds);
    }

    return 0;
}
