// Write  a  C/C++  program  to  perform  count  sort  on  an  integer 
// array to sort it in ascending order and compute the time 
// complexity for an input of size N.


#include <stdio.h>
#include <string.h>

void count_sort(int arr[], int n) {
    int count = 0, max = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        
    }

    int freq[max + 1];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        count++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (freq[i]-- > 0) {
            arr[index++] = i;
            count++;
        }
    }
    
    printf("Operation Count: %d\n", count);
}



int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    count_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
