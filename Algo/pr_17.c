// Write C/C++ program to implement stack with the use of array.
// Make  a  new  function  Multi  Pop  which  pops  k  times.  Take  k  as
// user  input.  Uses  amortize  analysis  (accounting)  to  calculate  time
// complexity of the program.

#include <stdio.h>

int count = 0; 

typedef struct {
    int arr[100];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->arr[++s->top] = value;
    
}

void pop(Stack *s) {
    if (s->top >= 0) {
        s->top--;
        count++;
    }
}

void multi_pop(Stack *s, int k) {
    if (k > s->top + 1) {
        printf("Not enough elements to pop. Popping all available elements.\n");
        k = s->top + 1; 
    }else{
    while (k-- > 0)
        pop(s);
    }
}



int main() {
    Stack s;
    s.top = -1;

    int n, val, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }

    printf("Enter k for MultiPop: ");
    scanf("%d", &k);
    multi_pop(&s, k);

    printf("Stack after MultiPop: ");
    for (int i = 0; i <= s.top; i++)
        printf("%d ", s.arr[i]);
    printf("\nOperation Count: %d\n", count);

    return 0;
}
