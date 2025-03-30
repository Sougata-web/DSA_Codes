// Write  a  C/C++  program  to  print  Fibonacci  series  upto  nth  term
// using  recursion  also  compute  the  time  complexity  in  terms  of
// input size.

#include <stdio.h>

int count = 0;

int fibonacci_recursive(int n)
{
    count+=2;
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\nOperation Count: %d\n", count);

    return 0;
}
