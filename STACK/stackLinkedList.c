#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
    int top;
    int data;
    struct node *prev;
} node;


    /* INITIALIZING THE STACK */
void initializeStack(node **head)
{
    node *temp = (node *)malloc(sizeof(node));
    *head = temp;
    temp->top = -1;
    temp->data = 0;
    temp->prev = NULL;
}


    /* PUSH FUNCTION */
void push(node **head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->prev = *head;
    *head = temp;
}

    /* POP FUNCTION */
void pop(node **head)
{
    node *pop = *head;
    if (pop->top == -1)
    {
        printf("\nStack is underflow : ERROR CODE 500 ");
    }
    else
    {
        node *temp = pop->prev;
        printf("\n%d", pop->data);
        free(pop);
        *head = temp;
    }
}

    /* PRINTING THE TOP VALUE */
void peek(node** head){
    node * temp = *head;
    printf("%d",temp->data);
}

    /* DISPLAYING THE ELEMENT */
void display(node **head){
    node *temp = *head;
    while(temp->top!=-1){
        printf("%d",temp->data);
        temp = temp->prev;
    }
}

int maxElement(node **head){
    node *temp = *head;
    int max = INT_MIN;
    while(temp->top != -1){
        if(max < temp->data)
            max = temp->data;
        temp = temp->prev;
    }
    printf("\n%d",max);
}

    /* MAIN FUNCTION */
int main()
{
    node *st = NULL;
    initializeStack(&st);
    push(&st, 5);
    push(&st, 4);
    push(&st, 3);
    push(&st, 2);
    push(&st, 1);
    peek(&st);
    printf("\n-------------\n");
    display(&st);
    printf("\n-------------\n");
    maxElement(&st);
    return 0;
}