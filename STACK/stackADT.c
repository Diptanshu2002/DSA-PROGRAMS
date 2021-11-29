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
/* -----ABOVE CODES ARE COMPULSORY FOR THE STACK TO WORK PROPERLY----- */

/*IS EMPTY FUNC */
void isEmpty(struct Stack *st){
    if(st->top<0){
        printf("\nThe stack is empty ❌");
        return;
    }
    printf("The stack is not empty 😃");
}

/*IS FULL FUNC */
void isFull(struct Stack *st){
    if(st->top == st->length-1){
        printf("\nThe stack is full 🥂");
        return;
    }
    printf("The stack is not full 😃");
}

/* POPPING ELEMENT OUT OF THE STACK AND PRINTING THE POPPED VALUE */
void pop(struct Stack *st){
    if(st->top<0){
        printf("\n-----Stack Underflow-----");
        return;
    }
    int popped = st->S[st->top--];
    printf("\n%d is popped out ",popped);
}

/* PUSHING INTO THE STACK AT TOP */
void push(struct Stack *st , int x){
    if(st->top >= st->length-1){
        printf("\n-----Stack Overflow-----");
        return;
    }
    st->top++;
    st->S[st->top] = x;
} 

/* DISPLAYING THE DATA INSIDE THE STACK */
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
    isFull(&st);
    display(&st);
}



