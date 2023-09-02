#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

struct person createPerson(int id, const char *name, int age, int height, int weight) {
    struct person p = {id, strdup(name), age, height, weight};
    return p;
}

void readData(struct person **people, int *n) {
    printf("Enter the number of students: ");
    scanf("%d", n);
    *people = (struct person *)malloc(*n * sizeof(struct person));
    printf("Id Name Age Height Weight(pound)\n");
    for (int i = 0; i < *n; i++) {
        int id, age, height, weight;
        char name[50];
        scanf("%d %s %d %d %d", &id, name, &age, &height, &weight);
        (*people)[i] = createPerson(id, name, age, height, weight);
    }
}

void createMinHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && people[left].age < people[smallest].age)
            smallest = left;
        if (right < n && people[right].age < people[smallest].age)
            smallest = right;
        if (smallest != i) {
            swap(&people[i], &people[smallest]);
            createMinHeap(people, n);
        }
    }
}

void createMaxHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && people[left].weight > people[largest].weight)
            largest = left;
        if (right < n && people[right].weight > people[largest].weight)
            largest = right;
        if (largest != i) {
            swap(&people[i], &people[largest]);
            createMaxHeap(people, n);
        }
    }
}

int youngestWeight(struct person *people) {
    return people[0].weight;
}

int main() {
    int option, n = 0;
    struct person *people = NULL;

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Create a Max-heap based on weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                readData(&people, &n);
                break;

            case 2:
                if (people == NULL)
                    printf("Please read data first (Option 1).\n");
                else {
                    createMinHeap(people, n);
                    printf("Min-heap based on age created.\n");
                }
                break;

            case 3:
                if (people == NULL)
                    printf("Please read data first (Option 1).\n");
                else {
                    createMaxHeap(people, n);
                    printf("Max-heap based on weight created.\n");
                }
                break;

            case 4:
                if (people == NULL)
                    printf("Please read data first (Option 1).\n");
                else
                    printf("Weight of youngest student: %d pounds\n", youngestWeight(people));
                break;

            case 5:
                if (people == NULL)
                    printf("Please read data first (Option 1).\n");
                else {
                    printf("Enter data for the new person: ");
                    int id, age, height, weight;
                    char name[50];
                    scanf("%d %s %d %d %d", &id, name, &age, &height, &weight);
                    people = (struct person *)realloc(people, (n + 1) * sizeof(struct person));
                    people[n++] = createPerson(id, name, age, height, weight);
                    createMinHeap(people, n);
                    printf("New person inserted into the Min-heap.\n");
                }
                break;

            case 6:
                if (people == NULL)
                    printf("Please read data first (Option 1).\n");
                else if (n == 0)
                    printf("Heap is empty.\n");
                else {
                    swap(&people[0], &people[--n]);
                    createMinHeap(people, n);
                    printf("Oldest person deleted from the Min-heap.\n");
                }
                break;

            case 7:
                printf("Exiting program.\n");
                if (people != NULL) {
                    for (int i = 0; i < n; i++)
                        free(people[i].name);
                    free(people);
                }
                break;

            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }
    } while (option != 7);

    return 0;
}

