#include <stdio.h>

// Function to perform Shell sort
void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for elements at gap intervals
        for (int i = gap; i < n; i++) {
            // Store the current element to be compared
            int temp = arr[i];

            // Shift earlier gap-sorted elements until the correct position is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // Place the current element at its correct position
            arr[j] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("\nArray after sorting: \n");
    printArray(arr, n);
    return 0;
}
