#include <stdio.h>

void printPattern(int N) {
    int center = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == center || j == center || i == j || i + j == N - 1 || (i < center && j == center - i) || (i > center && j == i - center) || (i < center && j == center + i) || (i > center && j == 3 * center - i)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter an odd value for N (>= 3): ");
    scanf("%d", &N);

    if (N % 2 == 0 || N < 3) {
        printf("Please enter a valid odd number greater than or equal to 3.\n");
        return 1;
    }

    printPattern(N);

    return 0;
}
