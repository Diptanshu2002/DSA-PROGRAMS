#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int size;
    char *s;
}stack;

void initializeStack(stack *st , int n){
    st->top = -1;
    st->size = n;
    st->s = (char *)malloc(n*sizeof(char));
}

int isOperand(char val){
    if(val == '+' || val == '-' || val == '/' || val == '*')
        return 0;

    else
        return 1;

}
int operatorPrecedence(char op){
    if(op == '+' || op == '-' )
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else
        return 0;
}

void push (stack *st,char n){
    st->top++;
    st->s[st->top]=n;
}

char pop(stack *st){
    return st->s[st->top--];
}

char* infixToPostfix(char *arr, stack *st){

    int i=0,j=0;
    char *postfix = (char*)malloc(st->size*sizeof(char));
    while(arr[i]!='\0'){

        if(isOperand(arr[i])){
            postfix[j] = arr[i];
            i++;
            j++;
        }

        else{

            if(st->top < 0){
                push(st,arr[i]);
                i++;
            }
            else if( operatorPrecedence(arr[i]) > operatorPrecedence(st->s[st->top])){
                push(st,arr[i]);
                i++;
            }
            else{
                postfix[j] = pop(st);
                //printf("/n%c",postfix[j]);
                j++;
            }
        }
    }
    while (st->top>=0)
    {
        /* code */
        postfix[j] = pop(st);
        j++;
    }
    
    return postfix;
}


int main(){
    //taking all inputs
    stack s1;
    int arrlen;
    printf("Enter Array Len : ");
    scanf("%d",&arrlen);
    initializeStack(&s1,arrlen);
    char arr[arrlen+1];
    printf("Enter the infix equation : ");
    scanf("%s",arr);
    char *newArr = infixToPostfix(arr,&s1);
    printf("%s",newArr);
    //

}