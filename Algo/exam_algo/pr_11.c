#include <stdio.h>
int get_max(int arr[], int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}

void counting_sort(int arr[],int n,int exp){
    int output[n],freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(arr[i]/exp)%10]++;

    }
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];

    }

    for(int i=n-1;i>=0;i--){
        output[freq[(arr[i]/exp)%10]-1]=arr[i];
        freq[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radix_sort(int arr[], int n){
    int max=get_max(arr, n);
    for(int exp=1;max/exp>0;exp*=10)
    counting_sort(arr,n,exp);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{

    int arr[] = {102, 354, 2, 1, 458, 3, 3, 232};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    radix_sort(arr, size);
    printArray(arr, size);

    return 0;
}