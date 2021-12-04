#include <stdio.h>
#include <stdlib.h>

//CREATING STRUCTURE OF QUEUE
typedef struct queue{
    int first;
    int rear;
    int *queueArr;
}queue;

//INITIALIZING QUEUE FOR THE FIRST TIME
void createQueue(queue *que , int n){
    que->queueArr = (int *)malloc(n*sizeof(int));
    que->first = -1;
    que->rear = -1;
}

//PUTTING VALUE INSIDE QUEUE AT LAST
void enQueue(queue *que, int val){
    que->rear++;
    que->queueArr[que->rear] = val;
}

//REMOVING VALUE FROM QUEUE FROM FIRST
int deQueue(queue *que){
    int poppedValue;
    que->first++;
    poppedValue = que->queueArr[que->first];
}

//DISPLAYING VALUE IN THE QUEUE FROM FIRST TO LAST
void display(queue *que){
    for (int i = que->first+1; i <= que->rear; i++)
    {
        printf("%d->",que->queueArr[i]);
    }
    
}

//IS EMPTY FUNCTION
void isEmpty(queue *que){
    if(que->first == que->rear)
            printf("The queue is empty");
    else
            printf("The queue is not empty");
}   
// MAIN FUNCTION
int main(){
    queue q1;
    int queueLen;
    printf("/nEnter the length of the queue");
    scanf("%d",&queueLen);
    createQueue(&q1 ,queueLen);
    enQueue(&q1,11);
    enQueue(&q1,12);
    enQueue(&q1,13);
    int pop = deQueue(&q1);
    printf("\n-----deleted-----%d\n",pop);
    display(&q1);
    return 0;
}