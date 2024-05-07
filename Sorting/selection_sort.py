def selectionSort(arr):
    n=len(arr)

    for i in range(n-1):
        min_idx=i
        for j in range(i+1,n):
            if arr[j]<arr[min_idx]:
                min_idx=j
        if(min_idx!=i):
            arr[min_idx],arr[i]=arr[i],arr[min_idx]

if __name__=="__main__":
    arr=[1,2,3,2,2,1,2,3,3,2]

    selectionSort(arr)

    print("Sorted array: ")
    for i in range(len(arr)):
        print("%d"%arr[i], end=" ")