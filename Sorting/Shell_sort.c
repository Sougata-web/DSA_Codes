#include<stdio.h>
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){

    int arr[]={1,2,3,4,2,1,3,5,5};

    int n=sizeof(arr)/sizeof(arr[0]);


    shellSort(arr,n);
    printArray(arr,n);



    
    return 0;
}