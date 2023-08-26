#include <stdio.h>

// Function to perform insertion sort
int insertion_sort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// Function to display the content of an array
void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *input_file;
    const char *output_file;
    
    switch (choice) {
        case 1:
            input_file = "inAsce.dat";
            output_file = "outInsAsce.dat";
            break;
        case 2:
            input_file = "inDesc.dat";
            output_file = "outInsDesc.dat";
            break;
        case 3:
            input_file = "inRand.dat";
            output_file = "outInsRand.dat";
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    // Read input data from the file
    FILE *inFile = fopen(input_file, "r");
    if (!inFile) {
        printf("Failed to open input file: %s\n", input_file);
        return 1;
    }

    int max_size = 500;
    int arr[max_size];
    int n = 0;
    while (fscanf(inFile, "%d", &arr[n]) == 1) {
        n++;
        if (n == max_size) {
            printf("Warning: Maximum number of elements exceeded.\n");
            break;
        }
    }
    fclose(inFile);

    // Perform insertion sort and count comparisons
    int comparisons = insertion_sort(arr, n);

    // Write sorted data to output file
    FILE *outFile = fopen(output_file, "w");
    if (!outFile) {
        printf("Failed to open output file: %s\n", output_file);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(outFile, "%d ", arr[i]);
    }
    fclose(outFile);

    // Display the sorted content and number of comparisons
    printf("Before Sorting (Content of the input file):\n");
    display_array(arr, n);

    printf("After Sorting (Content of the output file):\n");
    display_array(arr, n);

    printf("Number of Comparisons: %d\n", comparisons);

    // Determine the input scenario (best or worst case)
    if (choice == 1) {
        printf("Scenario: Best-case (Already sorted in ascending order)\n");
    } else if (choice == 2) {
        printf("Scenario: Worst-case (Sorted in descending order)\n");
    } else {
        printf("Scenario: Random data\n");
    }

    return 0;
}

