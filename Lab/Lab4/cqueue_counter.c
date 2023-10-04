#include <stdio.h>
#include <string.h>
#define CQ_SIZE 100

struct CQueue {
    int front, rear, c;
    int q[CQ_SIZE];
};

void init(struct CQueue *queue){
    queue->rear=-1;
    queue->front=-1;
    queue->c=0;
}

void insertq(struct CQueue *queue, int item) {
    if (queue->c==CQ_SIZE)
        printf("Queue overflow, cannot add %d\n",item);
    else{
        queue->rear=(queue->rear+1)%CQ_SIZE;
        queue->q[queue->rear] = item;
        queue->c++;
        }
}

int delq(struct CQueue *queue) {

    if (queue->c==0)
        printf("Queue empty\n");

    else{
        queue->front=(queue->front+1)%CQ_SIZE;
        queue->c--;
        return (queue->q[queue->front]);
        }
}

void display(struct CQueue *queue) {

    int i;
    i=(queue->front+1)%CQ_SIZE;
    int tempc= queue->c;
    while(tempc>0)
    {
        printf("%d\t",queue->q[i]);
        i=(i+1)%CQ_SIZE;
        tempc--;
    }
    printf("\n");
}

int main(){
    struct CQueue queue;
    init(&queue);
    int n[100], num;
    printf("Enter number of elements you want to enter:\n");
    scanf("%d",&num);
    printf("Enter queue elements:\n");
    for(int i=0;i<num;i++)
        scanf("%d",&n[i]);
    for(int i=0;i<num;i++)
        insertq(&queue, n[i]);
    display(&queue);
    delq(&queue);
    display(&queue);

}