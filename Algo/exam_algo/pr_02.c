#include<stdio.h>

int count=0;
int fibonacci_recursive(int n){
    count+=2;
    if(n<=1)
    return n;
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}
int main(){


    for(int i=0;i<5;i++){
        printf("%d ", fibonacci_recursive(i));
    }
    
    return 0;
}