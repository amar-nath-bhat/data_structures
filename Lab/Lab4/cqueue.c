#include <stdio.h>
#include <string.h>
#define CQ_SIZE 100

struct CQueue {
    int front, rear;
    int q[CQ_SIZE];
};

void init(struct CQueue *queue){
    queue->rear=0;
    queue->front=0;
}

void insertq(struct CQueue *queue, int item) {
    int r=queue->rear;
    int f=queue->front;
    if ((r=(r+1)%CQ_SIZE)==f)
        printf("Queue overflow, cannot add %d\n",item);

    else{
        queue->rear=(queue->rear+1)%CQ_SIZE;
        queue->q[queue->rear] = item;
        }
}

int delq(struct CQueue *queue) {

    if (queue->rear==queue->front)
        printf("Queue empty\n");

    int deletedItem = queue->q[queue->front%CQ_SIZE];
    queue->front=(queue->front+1)%CQ_SIZE;
    return deletedItem;
}

void display(struct CQueue *queue) {

    if (queue->rear==queue->front)
        printf("Queue empty\n");

    else{
        printf("Contents:");
        for (int i = (queue->front%CQ_SIZE); i != (queue->rear%CQ_SIZE); (++i)%CQ_SIZE)
            printf(" %d", queue->q[i+1]);
        printf("\n");
        }
}

int main(){
    struct CQueue queue;
    init(&queue);
    int n[100], num;
    printf("Enter number of elements you want to enter:\n");
    scanf("%d",&num);
    printf("Enter queue elements: ");
    for(int i=0;i<num;i++)
        scanf("%d",&n[i]);
    for(int i=0;i<num;i++)
        insertq(&queue, n[i]);
    display(&queue);
    delq(&queue);
    display(&queue);
}