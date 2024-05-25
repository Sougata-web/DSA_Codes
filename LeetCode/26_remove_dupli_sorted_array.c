#include <stdio.h>
int main()
{
    int i, k, n;
    printf("Enter the number of element you want to store in array:\n");
    scanf("%d", &n);
    int nums[n], expectedNumber[100];
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    while (i < n)
    {
        if (nums[i] == nums[i + 1])
        {
            /* code */
        }
    }
    return 0;
}