// Implement N-Queen problem

#include <stdio.h>
#include <stdbool.h>
#define N 8
// Function to print the chessboard
void printBoard(int board[N][N]) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at a given position
bool isSafe(int board[N][N], int row, int col) {
    int i,j;
    // Check the row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col) {
    int i;
    if (col >= N)
        return true;

    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};
    printf("Output of N- Queens problem\n");
    if (solveNQueens(board, 0)) {
        printf("Solution for %d-Queens problem:\n", N);
        printBoard(board);
    } else {
        printf("No solution exists for %d-Queens problem.\n", N);
    }

    return 0;
}
