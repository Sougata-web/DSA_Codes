// Write a C/C++ program to perform  selection sort on an integer
// array to sort it in ascending order and compute the time
// complexity for an input of size N.

#include <stdio.h>

void selection_sort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            count += 2;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            count += 3;
        }
    }
    printf("Operation Count: %d\n", count);
}

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selection_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
