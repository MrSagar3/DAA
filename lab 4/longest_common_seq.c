// Write a code for to implement Largest Common Sequence Algorithm
#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to find the Longest Common Subsequence (LCS)
int findLCS(char X[], char Y[], int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + findLCS(X, Y, m - 1, n - 1);
    else
        return max(findLCS(X, Y, m - 1, n), findLCS(X, Y, m, n - 1));
}

int main() {
    printf("-------Largest Common Sequence Algorithm-------\n");
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    int lcs_length = findLCS(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", lcs_length);

    return 0;
}
