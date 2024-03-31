#include<stdio.h>
#include<stdlib.h>
// int *twoSum(int* nums, int numsSize, int target, int* returnSize){
    
// }

//Two Sum Problem
int main(){

    int *nums,numsSize,target,i;
    printf("Enter the number of elements of array: \n");
    scanf("%d",&numsSize);
    nums=(int*)malloc(numsSize*sizeof(int));
    printf("Enter the array elements:\n");
    for(int i=0;i<numsSize;i++){
        scanf("%d",&nums[i]);
    }
    printf("Enter the target:\n");
    scanf("%d",&target);
    printf("The return size:\n");
    for(i=0;i<numsSize;i++){
        if((nums[i]+nums[i+1])==target){
            nums[0]=i;
            nums[0]=i+1;
            printf("%d",*nums);
        }
    }
    return 0;
}