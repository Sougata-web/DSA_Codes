#include<stdio.h>

int count=0;
int linear_search(int arr[], int n,int key){
    for(int i=0;i<n;i++){
        count++;
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){

    int arr[]={1,2,34,5,3,2,1,5};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int result=linear_search(arr,size,34);

    if(result!=-1)
        printf("%d", result);
    else
        printf("Key not found");
    
    return 0;
}