#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int size;
    int top;
    int *s;
}stack;

void initializeStack(stack *st , int n){
    st->size = n;
    st->top = -1;
    st->s = (int*)malloc(n*sizeof(int));
} 

void solve(stack *st){
    int i;
    while(st->top>=0){
        int counter = 0;
        int point = st->s[st->top];
        while(point>=0){
         if(st->s[st->top]>=st->s[point])
            counter++;
        point--;
        }
        printf("\n%d",counter);
        st->top--;
    
}}
void display(stack *st){
    while(st->top>=0)
        printf("%d",st->s[st->top--]);
}

int main()
{
    stack s1;
    int len,i;
    printf("enter : ");
    scanf("%d",&len);
    initializeStack(&s1,len);
    for(i=0;i<s1.size;i++){
        s1.top++;
        printf("enter numberes ; ");
        scanf("%d",&s1.s[s1.top]);
    }
    solve(&s1);
	return 0;
}