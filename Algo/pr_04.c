// Recursive Write a C/C++ program to perform binary search on
// an array of size N and compute time complexity for size N.

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
        if (arr[mid] > key)
            return binary_search(arr, left, mid - 1, key);
        return binary_search(arr, mid + 1, right, key);
    }
    return -1;
}

int main()
{
    int n, key;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    int result = binary_search(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Operation Count: %d\n", count);
    return 0;
}
