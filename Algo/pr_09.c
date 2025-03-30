// Write a C/C++ program to perform quick sort on an integer
// array to sort it in ascending order and compute the time
// complexity for an input of size N.

#include <stdio.h>

int count = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    count++;

    for (int j = low; j < high; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    count++;

    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    count++;
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
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

    quick_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nOperation Count: %d\n", count);

    return 0;
}
