#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int length;
    int *S;
};

void createStack(struct Stack *st){
    printf("Enter the size of the stack : ");
    scanf("%d",&st->length);
    st->top = -1;
    st->S = (int *)malloc(st->length*sizeof(int));
}

void pop(struct Stack *st){
    if(st->top<0){
        printf("\nStack Underflow");
        return;
    }
    int popped = st->S[st->top--];
    printf("\n%d is popped out ",popped);
}

void push(struct Stack *st , int x){
    if(st->top >= st->length-1){
        printf("\n-----Stack Overflow-----");
        return;
    }
    st->top++;
    st->S[st->top] = x;
} 

void display(struct Stack *st){
    int first;
    first = st->top;
    while (first>=0)
    {
        printf("\n%d",st->S[first]);
        first--;
    }
    
}

int main(){
    struct Stack st;
    createStack(&st);
    push(&st,25);
    push(&st,24);
    pop(&st);
    display(&st);
}



