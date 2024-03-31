#include <stdio.h>
int main()
{
    int i, j, c = 5, r = 6;
    int a[r][c];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            a[i][j] = (i * j + 1);
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
             printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}