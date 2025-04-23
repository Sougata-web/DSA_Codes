#include<stdio.h>
void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    largest=left;
    if(right<n && arr[right]>arr[largest])
    largest=right;

    if(largest!=i){
        int temp= arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        heapify(arr,n, largest);
    }
}

void delete_heap(int arr[], int *n){
    if(*n == 0)return;
    arr[0]=arr[*n-1];
    (*n)--;
    heapify(arr,*n,0);
}
int main(){
    int n;
    printf("Enter number of elements in heap: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter heap elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of deletions: ");
    int d;
    scanf("%d", &d);

    for (int i = 0; i < d; i++)
        delete_heap(arr, &n);

    printf("Heap after deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
   
    
    return 0;
}