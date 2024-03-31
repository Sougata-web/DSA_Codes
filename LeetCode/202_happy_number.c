#include<stdio.h>
#include<stdlib.h>
    int isHappy(int num){
        int rem=0,sum=0;
        while(num>0){
            rem=num%10;
            sum=sum+(rem*rem);
            num=num/10;
        }
        return sum;
    }
int main(){
    int num,counter=0;
    printf("Enter any number other than 1 and 0:\n");
    scanf("%d",&num);
    int res=num;
    while(res !=1 && res!=4){
       res= isHappy(res);
            counter++;

    }

    if(res==1){
        printf("It's a happy number!!\n");
        printf("True.\n");
        printf("Counter: %d",counter);
    }
    else if(res==4){
        printf("It's not a happy number.\n");
        printf("False.\n");
        printf("Counter: %d",counter);

    }
    return 0;
}