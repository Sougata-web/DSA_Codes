#include<stdio.h>
#include<stdlib.h>

void insert(int **arr, int *size,int *capacity,int value){
    if(*size==*capacity){
        *capacity*=2;
        *arr=realloc(*arr,*capacity * sizeof(int));

    }
    (*arr)[(*size)++]=value;
}
int main(){
    int capacity = 1, size = 0;
    int *arr = malloc(capacity * sizeof(int));
    int value;

    printf("Enter elements (-1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1)  // Sentinel value to stop input
            break;
        insert(&arr, &size, &capacity, value);
    }

    printf("Dynamic Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    free(arr);
    
    return 0;
}