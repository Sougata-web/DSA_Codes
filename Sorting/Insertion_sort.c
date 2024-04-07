#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{

    int arr[] = {
        1,
        1,
        2,
        3,
        4,
        3,
        2,
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    printArray(arr, n);

    return 0;
}