#include <stdio.h>

#define MAX 20

int board[MAX];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row) {
            return 0;
        }
    }
    return 1;
}

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1, n);
        }
    }
}

int main() {
    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    solve(0, n);

    return 0;
}
