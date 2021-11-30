#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int size;
    int *c;
};

void initializing(struct stack *st){
    int len;
    char str[20];
    len = strlen(str);
    st->top = -1;
    st->size = len+1;
    st->c = (struct stack *)malloc(st->size*sizeof(char));
}

int main(){

}