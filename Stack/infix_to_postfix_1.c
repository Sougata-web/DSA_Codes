#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUMBER_CHAR 100

int precedence(char c){
    if(c=='^')
        return 3;
    else if(c=='/' || c=='*')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}

char associativity_rule(char c){
    if(c=='^')
        return 'R';
    return 'L';
}

void infix_to_postfix(char s[]){
    char stack[MAX_NUMBER_CHAR];
    int result_index=0;
    char result[MAX_NUMBER_CHAR];
    int len= strlen(s);
    int stack_index=-1;

    for(int i=0;i<len;i++){
        char c= s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='1'&& c<='9')){
            result[result_index++]=c;
        }
        else if(c== '('){
            stack[++stack_index]=c;
        }
        else if(c==')'){
            while(stack_index>=0 && stack[stack_index] != ')'){
                result[result_index++]=stack[stack_index--];

            }
            stack_index--;
        }
        else{
            while(stack_index>=0 && ((precedence(s[i])<precedence(stack[stack_index])||(precedence(s[i])==precedence(stack[stack_index]))&&associativity_rule(s[i])=='L'))){
                result[result_index++]=stack[stack_index--];
            }
            stack[++stack_index]=c;
        }
    }
    while(stack_index>=0){
        result[result_index++]=stack[stack_index--];

    }
    result[result_index]=='\0';
    printf("%s\n",result);

}
int main(){
   
    char exp[100];
    
    printf("Enter the expression: \n");
    scanf("%[^\n]s",exp);

    infix_to_postfix(exp);
    
    return 0;
}