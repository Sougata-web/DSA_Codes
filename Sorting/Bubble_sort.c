#include <stdio.h>
int main()
{
    int i, j, n, tmp, f = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        f = 0;
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                f++;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (f == 0)
        {
            break;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}