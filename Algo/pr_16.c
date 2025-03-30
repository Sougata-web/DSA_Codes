// Write  a  C/C++  program  to  implement  dynamic  array.  First  take 
// maximum length of array from user input. Then start by creating 
// array of size 1, and start taking input. Every time the array is full, 
// double its capacity. Use amortize analysis (aggregate) to calculate 
// time complexity of the program.


#include <stdio.h>
#include <stdlib.h>

int count = 0;

void insert(int **arr, int *size, int *capacity, int value) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = realloc(*arr, *capacity * sizeof(int));
        count++;
    }
    (*arr)[(*size)++] = value;
}


int main() {
    int capacity = 1, size = 0;
    int *arr = malloc(capacity * sizeof(int));

    printf("Enter number of elements: ");
    int n, value;
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&arr, &size, &capacity, value);
    }

    printf("Dynamic Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\nOperation Count: %d\n", count);

    free(arr);
    return 0;
}
