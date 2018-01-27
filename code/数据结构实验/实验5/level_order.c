/*
给出一棵二叉树的先序（或后序）遍历结果，以
及中序遍历结果，如何构造这棵树？假定遍历结
果以数组方式输入，请写出相应函数，判断是否
存在生成同样遍历结果的树，如果存在，构造这
棵树。
 */

#include <stdio.h>
#include <stdlib.h>

//二叉链表类型定义
typedef struct TNode
{
    int val;
    struct TNode *left, *right;
} TNode, *BTree;


//链队列类型定义
typedef struct LinkedQueueNode
{
    TNode *node;
    struct LinkedQueueNode *next;
} LinkedQueueNode;


typedef struct LinkedQueue
{
    LinkedQueueNode *head, *rear;
} LinkedQueue;


//初始化队列
void initQueue(LinkedQueue *linkedQueue)
{
    LinkedQueueNode *p;
    p = (LinkedQueueNode *) malloc(sizeof(LinkedQueueNode));
    linkedQueue->head = p;
    linkedQueue->rear = p;
    linkedQueue->head->next = NULL;
}


//判断队列是否为空
int isEmptyQueue(LinkedQueue *linkedQueue)
{
    if (linkedQueue->head == linkedQueue->rear)
        return 1;
    else
        return 0;
}


//入队列
void enQueue(LinkedQueue *linkedQueue, BTree x)
{
    LinkedQueueNode *p;
    p = (LinkedQueueNode *) malloc(sizeof(LinkedQueueNode));
    p->node = x;
    p->next = NULL;
    linkedQueue->rear->next = p;
    linkedQueue->rear = p;
}


//出队列
int outQueue(LinkedQueue *linkedQueue)
{
    LinkedQueueNode *s;
    if (isEmptyQueue(linkedQueue)) {
        exit(0);
    } else {
        s = linkedQueue->head->next;
        linkedQueue->head->next = s->next;
        if (s->next == NULL)
            linkedQueue->rear = linkedQueue->head;
        free(s);
        return 1;
    }
}


//取队列首元素
BTree getHead(LinkedQueue *linkedQueue)
{
    LinkedQueueNode *p;
    TNode *q;
    if (isEmptyQueue(linkedQueue))
        return q;
    else {
        p = linkedQueue->head->next;
        return p->node;
    }
}


//建二叉树
BTree initiateTree()
{
    BTree root = (BTree) malloc(sizeof(TNode));
    BTree head = root;
    root->val = 1;
    BTree temp;
    root->left = (BTree) malloc(sizeof(TNode));
    temp = root->left;
    temp->val = 2;
    root->right = (BTree) malloc(sizeof(TNode));
    temp = root->right;
    temp->val = 3;

    root = head->left;
    root->left = (BTree) malloc(sizeof(TNode));
    temp = root->left;
    temp->val = 4;
    root->right = (BTree) malloc(sizeof(TNode));
    temp = root->right;
    temp->val = 5;

    root = root->left;
    root->left = (BTree) malloc(sizeof(TNode));
    temp = root->left;
    temp->val = 8;
    root->right = (BTree) malloc(sizeof(TNode));
    temp = root->right;
    temp->val = 9;

    root = head->right;
    root->left = (BTree) malloc(sizeof(TNode));
    temp = root->left;
    temp->val = 6;
    root->right = (BTree) malloc(sizeof(TNode));
    temp = root->right;
    temp->val = 7;

    return head;

}

void printNode(BTree p)
{
    printf(" %d ", p->val);
}

int getHeight(BTree t)
{
    int left_height, right_height;
    if (t == NULL)
        return 0;
    else {
        left_height = getHeight(t->left);
        right_height = getHeight(t->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

//层次遍历
void levelOrder(BTree bt)
{
    LinkedQueue queue;
    BTree p;
    initQueue(&queue);
    if (bt != NULL)
    {
        enQueue(&queue, bt);
        while (!isEmptyQueue(&queue)) {
            p = getHead(&queue);
            outQueue(&queue);
            printNode(p);
            if (p->left != NULL)
                enQueue(&queue, p->left);
            if (p->right != NULL)
                enQueue(&queue, p->right);
        }
    }
}


int main()
{
    BTree t;
    t = initiateTree();

    printf("\n二叉树的高度为:%d\n", getHeight(t));
    printf("\n层次遍历序列为:");
    levelOrder(t);
    printf("\n\n");
}

