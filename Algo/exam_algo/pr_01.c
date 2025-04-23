#include<stdio.h>

void fibonacci_iterative(int n){
    int a =0, b=1, next, count=0;
    printf("Fibonacci series: %d %d ", a,b);
    count+=2;
    for(int i=2;i<n;i++){
        next=a+b;
        printf("%d ", next);
        a=b;
        b=next;
        count++;
    }
    printf("\nOperation Count: %d", count);
}


int main(){

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    fibonacci_iterative(n);
    
    return 0;
}