#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);

        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option, n, arr[500];
    clock_t start, end;

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n2. Descending Data\n3. Random Data\n4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4) {
            printf("Exiting the program.\n");
            break;
        }

        FILE *inputFile = NULL;
        if (option == 1) inputFile = fopen("inAsce.dat", "r");
        else if (option == 2) inputFile = fopen("inDesc.dat", "r");
        else if (option == 3) inputFile = fopen("inRand.dat", "r");
        else {
            printf("Invalid option. Please choose a valid option.\n");
            continue;
        }

        n = 0;
        while (fscanf(inputFile, "%d", &arr[n]) == 1) n++;
        fclose(inputFile);

        printf("Before Sorting: ");
        printArray(arr, n);

        comparisons = 0;
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        printf("After Sorting: ");
        printArray(arr, n);

        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == (n * (n - 1)) / 2) {
            printf("Scenario: Best-case partitioning\n");
        } else if (comparisons == ((n * (n - 1)) / 2) + (n - 1)) {
            printf("Scenario: Worst-case partitioning\n");
        } else {
            printf("Scenario: Neither best-case nor worst-case\n");
        }

        double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Execution Time: %.9f seconds\n", execution_time);
    }

    return 0;
}

