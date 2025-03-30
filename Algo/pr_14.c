// Write a C/C++ program to build a heap using heapify and use 
// it to perform heap sort, also  compute the time  complexity for an 
// input of size N. 

#include <stdio.h>

int count = 0;

void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    count++;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        count++;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        count++;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        count ++;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        count ++;
        heapify(arr, i, 0);
    }
}

// Time Complexity: O(N log N)

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heap_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nOperation Count: %d\n", count);

    return 0;
}
