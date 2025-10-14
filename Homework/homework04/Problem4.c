#include <stdio.h>

int main() {
    int N;

    while (1) {
        printf("Enter a positive integer for N: ");
        if (scanf("%d", &N) == 1) { // 
            if (N > 0) {
                break;
            } else {
                printf("Error: N must be a positive integer. Please try again.\n");
            }
        } else {
            printf("Error: Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
        }
    }

    printf("Starting fizz-buzz up to %d:\n", N);

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("fizz-buzz\n");
        } else if (i % 3 == 0) {
            printf("fizz\n");
        } else if (i % 5 == 0) {
            printf("buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}