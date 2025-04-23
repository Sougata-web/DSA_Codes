#include<stdio.h>

void merge(int arr[], int temp[], int left, int mid,int right){
    int left_end, temp_pos,i,size;
    left_end=mid-1;
    temp_pos=left;
    size=right-left+1;
    while((left<=left_end) &&(mid<=right)){
        if(arr[left]<arr[mid]){
            temp[temp_pos]=arr[left];
            temp_pos++;
            left++;
        }
        else{
            temp[temp_pos]=arr[mid];
            temp_pos++;
            mid++;
        }
    }

    while(left<=left_end){
        temp[temp_pos]=arr[left];
        left++;
        temp_pos++;
    }

    while(mid<=right){
        temp[temp_pos]=arr[mid];
        mid++;
        temp_pos++;
    }
    for(int i=0;i<=size;i++){
        arr[right]=temp[right];
        right--;
    }

}

void mergeSort(int arr[],int temp[], int left, int right){
    int mid;
    if(right>left){
        mid=left+(right-left)/2;
        mergeSort(arr, temp,left,mid);
        mergeSort(arr,temp,mid+1,right);
        merge(arr, temp, left,mid+1,right);
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
    int temp[size];
    mergeSort(arr,temp,0,size-1);
    printArray(arr, size);
    
    return 0;
}