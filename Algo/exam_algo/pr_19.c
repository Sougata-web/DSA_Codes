#include <stdio.h>

void fibonacci_dp(int n) {
    int fib[n];
    int count = 0;

    if (n >= 1) {
        fib[0] = 0;
        printf("Fibonacci series: %d ", fib[0]);
        count++;
    }

    if (n >= 2) {
        fib[1] = 1;
        printf("%d ", fib[1]);
        count++;
    }

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("%d ", fib[i]);
        count++;
    }

    printf("\nOperation Count: %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fibonacci_dp(n);

    return 0;
}
