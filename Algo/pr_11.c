// Write  a  C/C++  program  to  perform  radix  sort  on  an  integer 
// array to sort it in ascending order and compute the time 
// complexity for an input of size N. 

#include <stdio.h>

int count = 0;

int get_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
       
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void counting_sort(int arr[], int n, int exp) {
    int output[n], freq[10] = {0};

    for (int i = 0; i < n; i++) {
        freq[(arr[i] / exp) % 10]++;
        count++;
    }

    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
        count++;
    }

    for (int i = n - 1; i >= 0; i--) {
        output[freq[(arr[i] / exp) % 10] - 1] = arr[i];
        freq[(arr[i] / exp) % 10]--;
        count++;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        count++;
    }
}

void radix_sort(int arr[], int n) {
    int max = get_max(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(arr, n, exp);
        count++;
    }
}


int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radix_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nOperation Count: %d\n", count);

    return 0;
}

