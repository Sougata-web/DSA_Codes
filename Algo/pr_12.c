// Write a C/C++ program to insert an element into heap, also 
// compute time complexity for an input of size N

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;
int count = 0; // Complexity count

void heap_insert(int value) {
    heap[size] = value;
    int i = size;
    count++; 

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        
        int temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
        count ++; 
    }
    size++;
}

void print_heap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\nOperation Count: %d\n", count);
}



int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        heap_insert(val);
    }

    printf("Heap after insertion: ");
    print_heap();
    return 0;
}
