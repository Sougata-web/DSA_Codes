#include<stdio.h>

void maxHeapify(int Arr[],int n,int i){
    int largest=i;
    int l=(2*i);
    int r=(2*i)+1;

    while(l<=n && Arr[l]>Arr[largest]){
        largest=l;
    }
    while(r<=n && Arr[r]>Arr[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(Arr[largest],Arr[i]);
        maxHeapify(Arr,n,largest);
    }
}

int swap(int xp,int yp){
    int temp=xp;
    xp=yp;
    yp=temp;
}

void heapSort(int Arr[],int n){
    for(int i=n/2;i>=1;i--){
        maxHeapify(Arr,n,i);
    }
    for(int i=n;i>-1;i--){
        swap(Arr[1],Arr[i]);
        maxHeapify(Arr,n,i);
    }
}
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr,arr_size);

    for(int i=0;i<arr_size;i++){
        printf("%d ",arr[i]);
    }
    


    
    return 0;
}