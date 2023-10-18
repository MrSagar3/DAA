// Write a suitable code to implement randomized quick sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to choose a random pivot and partition the array
int partition(int arr[], int low, int high) {
    // Generate a random index within the range [low, high]
    int randomIndex = low + rand() % (high - low + 1);

    // Swap the pivot element (randomly chosen) with the last element
    swap(&arr[randomIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform randomized quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(NULL)); // Seed for the random number generator

    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("Unsorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
