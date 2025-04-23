#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])
            min_idx=j;
        }
        if(min_idx!=i){
            swap(&arr[min_idx],&arr[i]);
        }
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
    selection_sort(arr,size);
    printArray(arr, size);
    
    return 0;
}