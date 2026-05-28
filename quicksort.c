#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
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
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void runTest(int size) {
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    clock_t start = clock();

    quickSort(arr, 0, size - 1);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array Size: %d\tTime Taken: %f seconds\n", size, time_taken);

    free(arr);
}

int main() {
    srand(time(NULL));

    int sizes[] = {10000, 20000, 30000, 40000, 50000,
                   60000, 70000, 80000, 90000, 100000};

    int n = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < n; i++) {
        runTest(sizes[i]);
    }

    return 0;
}
