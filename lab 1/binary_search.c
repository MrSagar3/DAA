// Implement the binary search algorithm to search 31 in given array 
//  10 , 14, 19, 26, 31, 42, 44

#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;      
        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int arr[] = {10, 14, 19, 26, 31, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 31;
    int result = binarySearch(arr, 0, n - 1, target);
    printf("Binary Search\n");
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
