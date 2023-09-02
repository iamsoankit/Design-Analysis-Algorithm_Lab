#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high, int* comparisons) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1); // Initialize the index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high, int* comparisons) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons);

        quickSort(arr, low, pivotIndex - 1, comparisons); // Sort elements before pivot
        quickSort(arr, pivotIndex + 1, high, comparisons); // Sort elements after pivot
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[] = {7, 9, 2, 11, 19, 17, 12, 5, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    printf("Input array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1, &comparisons);

    printf("Quick Sort: ");
    printArray(arr, n);

    printf("Comparisons made: %d\n", comparisons);

    return 0;
}

