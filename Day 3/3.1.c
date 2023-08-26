#include <stdio.h>

int binary_search_leftmost(int arr[], int size, int target, int *comparisons) {
    int left = 0;
    int right = size - 1;
    int position = -1;
    *comparisons = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        
        if (arr[mid] == target) {
            // We found the target, but we need to check for the leftmost position
            position = mid;
            right = mid - 1;  // Move left to find the leftmost occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return position;
}

int main() {
    int size, target, i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter elements of the array (sorted): ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key to be searched: ");
    scanf("%d", &target);
    
    int comparisons;
    int position = binary_search_leftmost(arr, size, target, &comparisons);
    
    if (position != -1) {
        printf("Element %d found at position %d (0-indexed)\n", target, position);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    
    printf("Number of comparisons made: %d\n", comparisons);
    
    return 0;
}

