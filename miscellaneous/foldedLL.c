#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;    
};
void print(struct node *head) {
    
}
void display(struct node **head){
    struct node*current = *head;
    printf("Link list data:");
    while(current!=NULL){
        printf("%d ",current->data);
        current = current->next;
    }
}

void create(struct node **head,int data) 
{
    int i;
    struct node* current = *head;
    scanf("%d",&current->data);
    current->next = NULL;
    current->prev = NULL;
    for(i=1;i<data;i++){
        struct node* prevNode = current;
        struct node *newNode  = (struct node*)malloc(sizeof(struct node));
        current->next = newNode;
        current=newNode;
        scanf("%d",&current->data);
        current->prev = prevNode;
        current->next=NULL;
        prevNode  = current;
}    
}

void fold(struct node **head , int datalen){
    struct node* first = *head;
    struct node* last = *head;
    while (last->next!=NULL)
        last = last->next;

    int i;
    printf("\nLink list data after fold:");
    for(i=0;i<datalen;i++){
        if(i%2==0){
           printf("%d ",first->data); 
           first = first->next;
        }
        else{
        printf("%d ",last->data);
        last = last->prev;}
    }
}

int main()
{
    int dataLen;
    scanf("%d",&dataLen);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    create(&head,dataLen);
    display(&head);
    fold(&head,dataLen);
	return 0;
}