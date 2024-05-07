#include <stdio.h>

// Function to compute the minimum of four values
int min(int a, int b, int c, int d)
{
    int min_val = a;
    if (b < min_val)
        min_val = b;
    if (c < min_val)
        min_val = c;
    if (d < min_val)
        min_val = d;
    return min_val;
}

int main()
{
    int n; // Size of the square matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int A[n][n];      // Input matrix
    int result[n][n]; // Resultant matrix

    // Input the elements of matrix A
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Compute the resultant matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int f_xy = 4 * i * min(A[i][j], A[i][j + 1], A[i + 1][j + 1], A[i + 1][j]);
            result[i][j] = f_xy;
        }
    }

    // Print the resultant matrix
    printf("Resultant matrix:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
