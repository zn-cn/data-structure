#include <stdio.h>

#define MAX_SIZE  (10)

static int queue[MAX_SIZE];
static int rear=0;
static int front=0; 

#define IS_empty (rear==front)
#define IS_full (front==MAX_SIZE-1)
#define Enqueue(x) queue[++rear]=(x)
#define Dequeue (queue[front--],rear-- )

//**************
static int enqueue(int data){
    Enqueue(data);
    for(int i=0;i<MAX_SIZE;i++){
        printf("%d  ",queue[i]);
    }
}

static int dequeue(){
    if (!IS_empty){
        Dequeue;
    }
    else{
        printf("queue is empty");
    }
}

int main(){
    int type=0;
    while (type!=3){
        printf("1 进队；2出对;3结束");

        scanf("%d",&type);
        int data;
        if (data==1)
        {
            scanf("%d",&data);
            enqueue(data);
        }
        else if (data==2)
        {
            dequeue;
        }
        else if (data==3){
            break;
        }
    }
}
