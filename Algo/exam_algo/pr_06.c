#include<stdio.h>

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=key;

    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
int main(){

    int arr[]={1,3,2,1,4,53,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);
    printArray(arr, size);
    
    return 0;
}