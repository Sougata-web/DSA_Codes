// Write a C/C++ program to perform insertion sort on an integer 
// array to sort it in ascending order and compute the time 
// complexity for an input of size N.

#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        count++; 
        while (j >= 0 && arr[j] > key) {
            count++; 
            arr[j + 1] = arr[j];
            j--;
            count++; 
        }
        arr[j + 1] = key;
        count++;
    }
    printf("Operation Count: %d\n", count);
}


int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertion_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
