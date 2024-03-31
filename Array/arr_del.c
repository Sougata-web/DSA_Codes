#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr, i, val, size, k;
    printf("Enter the number of elements you want to store in array:\n");
    scanf("%d", &k);
    arr = (int *)malloc(k * sizeof(int));
    printf("Enter the array elements:\n");
    for (i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value you want to delete:\n");
    scanf("%d", &val);
    for (i = 0; i < k; i++)
    {
        if (arr[i] == val)
        {
            for (int j = i; j < k - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            k--;
        }
    }
    printf("The updated array:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}