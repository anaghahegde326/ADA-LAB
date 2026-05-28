#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void runTest(int size) {
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    clock_t start = clock();

    heapSort(arr, size);

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
