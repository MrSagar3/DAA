// implement the min-max algorithm to find the minimum number in the the given array 
// 5,7,3,4,9,12,6,2
#include <stdio.h>
void findMinAndMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMinAndMax(arr, n, &min, &max);
    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);
    return 0;
}
