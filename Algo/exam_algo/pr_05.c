#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[], int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            count++;
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                count++;
            }
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
    bubble_sort(arr,size);
    printArray(arr, size);
    
    return 0;
}