#include <stdio.h>

int main() {
    int m, n, p;
    int i, j, k;

    // Read dimensions of Matrix A
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Read Matrix A
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read dimensions of Matrix B
    int rowsB, colsB;
    scanf("%d %d", &rowsB, &colsB);

    // Check whether multiplication is possible
    if (n != rowsB) {
        printf("Invalid input");
        return 0;
    }

    int B[rowsB][colsB];
    int C[m][colsB];

    // Read Matrix B only if multiplication is possible
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize result matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < colsB; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (i = 0; i < m; i++) {
        for (j = 0; j < colsB; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result
    for (i = 0; i < m; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d", C[i][j]);
            if (j < colsB - 1)
                printf(" ");
        }
        printf(" \n");
    }

    return 0;
}
