#include <stdio.h>
#include <limits.h>

// Function to print the matrix
void printMatrix(int matrix[][100], int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the optimal parenthesization
void printOptimalParenthesis(int S[][100], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(S, i, S[i][j]);
        printOptimalParenthesis(S, S[i][j] + 1, j);
        printf(")");
    }
}

// Function to find the minimum number of multiplications
int matrixChainOrder(int arr[], int n) {
    int M[100][100];
    int S[100][100]; // S matrix for optimal parenthesization
    int i, j, k, L, q;

    // Initialize M and S matrices
    for (i = 1; i <= n; i++) {
        M[i][i] = 0;
        S[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            M[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = M[i][k] + M[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k; // Store the value of k for optimal parenthesization
                }
            }
        }
    }

    printf("Multiplication:\n");
    printf("Minimum number of multiplications: %d\n", M[1][n]);

    printf("\nMatrix Sequence:\n");
    for (int m = 1; m <= n; m++) {
        printf("A%d", arr[m - 1]);
        if (m < n) {
            printf(" x ");
        }
    }

    printf("\n\nOptimal Parenthesization: ");
    printOptimalParenthesis(S, 1, n);
    printf("\n");

    printf("\nM Matrix:\n");
    printMatrix(M, n, n);

    printf("\nS Matrix:\n");
    printMatrix(S, n, n);

    return M[1][n];
}

int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]) - 1;

    matrixChainOrder(arr, n);

    return 0;
}
