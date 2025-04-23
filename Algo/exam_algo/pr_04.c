#include <stdio.h>

int count = 0;

int binary_search(int arr[], int left, int right, int key)
{
    count++;
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binary_search(arr, left, mid - 1, key);
        else
            return binary_search(arr, mid + 1, right, key);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 34}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int result = binary_search(arr, 0, size - 1, key);

    if (result != -1)
        printf("Key found at index: %d\n", result);
    else
        printf("Key not found\n");

    printf("Function calls (Count): %d\n", count);
    return 0;
}
