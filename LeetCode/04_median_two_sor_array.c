#include <stdio.h>
#include <stdlib.h>
int main()
{   int i = 0, j = 0, k = 0, m, n, sum = 0, count = 0;
    int *arr1, *arr2, *arr_m;
    float res;
    arr1 = (int *)malloc(m * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    arr_m = (int *)malloc((m + n) * sizeof(int));
    printf("Enter the number of elements you wnat to store in first array:\n");
    scanf("%d", &m);
    printf("Enter the first array elements (in a sorted manner): \n");
    for (i = 0; i < m; i++)
    {scanf("%d", &arr1[i]);}
    printf("Enter the number of elements you want to store in second array:\n");
    scanf("%d", &n);
    printf("Enter the second array elements (in a sorted manner): \n");
    for (j = 0; j < n; j++)
    {   scanf("%d", &arr2[j]);}
    i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {if (arr1[i] <= arr2[j])
        { arr_m[k] = arr1[i];i++;
        }
        else{arr_m[k] = arr2[j];j++;
        } k++;}
    while (i < m)
    {arr_m[k] = arr1[i]; i++;k++;}
    while (j < n)
    {arr_m[k] = arr2[j];j++;k++;
    }
    for (i = 0; i < m + n; i++)
    {arr_m[i];}
    int merge_arr_len = sizeof(arr_m) / sizeof(arr_m[0]);
    if (merge_arr_len % 2 == 0)
    {for (i = 0; i < m + n; i++)
     {sum = sum + arr_m[i];count++;res = (float)sum / count;}
    }
    else
    {res = (float)arr_m[i / 2];
    } printf("\nMedian is: %f", res);
    return 0;
}