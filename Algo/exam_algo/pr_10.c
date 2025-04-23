#include <stdio.h>

// count sort

void count_sort(int arr[], int n, int b[], int k)
{
    int c[k], i, j;
    for (i = 0; i < k; i++)
        c[i] = 0;
    for (j = 0; j < n; j++)
        c[arr[j]] = c[arr[j]] + 1;
    for (i = 1; i < k; i++)
        c[i] = c[i] + c[i - 1];
    for (j = n - 1; j >= 0; j--)
    {
        b[c[arr[j]] - 1] = arr[j];
        c[arr[j]] = c[arr[j]] - 1;
    }
    for(int i=0;i<n;i++)
    arr[i]=b[i];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{

    int arr[] = {1, 3, 2, 1, 4, 3, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int temp[size];
    count_sort(arr, size, temp, 5);
    printArray(arr, size);

    return 0;
}