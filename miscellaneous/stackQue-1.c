/*
Given binary string str of size N the task is to check if the given string is valid or not. A
string is called valid if the number of 0's equals the number of 1's and at any moment starting
from the left of the string number 0's must be greater than or equals to the number of 1's.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int length;
    int top;
    char *arr;
}stack;

void createStack (stack *s , int len){
    s->length = len+1;
    s->top = -1;
    s->arr = (char *)malloc(s->length*sizeof(char));
}

void eqBinary(stack *s){
    int i=0;
    int counter0=0,counter1=0;
    printf("Enter the Binary Character : ");
    for(i=0;i<s->length;i++){
        s->top++;
        scanf("%c",&s->arr[i]);
    }


    while (s->top>=0)
    {

        if(s->arr[s->top]=='1'){
            counter1++;
            s->top--;
        }
        else if(s->arr[s->top]=='0'){
            counter0++;
            s->top--;
        }
        else{
            s->top--;
        }
    }

    if(counter0 == counter1)
        printf("Yes");
    else
        printf("No");
    
}

void display(stack *st){
    while (st->top>=0)
    {
        printf("%c",st->arr[st->top--]);
    }
    
}
int main(){

    int n;
    printf("Enter the number of character : ");
    scanf("%d",&n);
    if(n%2!=0){
        printf("no");
        return 0;
    }
    stack st;
    createStack(&st,n);
    eqBinary(&st);
    return 0;
}
