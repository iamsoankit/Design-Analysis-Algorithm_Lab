#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int option, n, arr[500];
    clock_t start, end;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
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
        mergeSort(arr, 0, n - 1);
        end = clock();

        printf("After Sorting: ");
        printArray(arr, n);

        printf("Number of Comparisons: %d\n", comparisons);
        double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Execution Time: %.9f seconds\n", execution_time);
    }

    return 0;
}

