// Write a C/C++ program using linear search to search an element
// in an array also compute time complexity for an input of size N.

#include <stdio.h>

int linear_search(int arr[], int n, int key, int *count)
{
    for (int i = 0; i < n; i++)
    {
        (*count)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key, count = 0;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    int result = linear_search(arr, n, key, &count);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Operation Count: %d\n", count);
    return 0;
}
