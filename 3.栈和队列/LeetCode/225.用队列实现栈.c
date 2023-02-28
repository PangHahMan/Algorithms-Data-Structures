// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef int QDataType;
// 队列里队头和队尾的结构
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode *next;
} QNode;

// 队列的结构
typedef struct Queue
{
    QNode *front; // 队头
    QNode *rear;  // 队尾
    size_t size;  // 队列长度
} Queue;

// 队列的初始化
void QueueInit(Queue *pq);
// 队列的销毁
void QueueDestroy(Queue *pq);
// 进队列
void QueuePush(Queue *pq, QDataType x);
// 出队列
void QueuePop(Queue *pq);
// 取队头数据
QDataType QueueFront(Queue *pq);
// 取队尾数据
QDataType QueueBack(Queue *pq);
// 判断队列是否为空
bool QueueEmpty(Queue *pq);
// 队列长度
size_t QueueSize(Queue *pq);
// 打印队列
void QueuePrint(Queue *pq);

// 队列的初始化
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

// 队列的销毁
void QueueDestroy(Queue *pq)
{
    assert(pq);
    QNode *cur = pq->front;
    while (cur)
    {
        QNode *nextnode = cur->next;
        free(cur);
        cur = nextnode;
    }
    pq->front = pq->rear = NULL;
    pq->size = 0;
}

// 进队列
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    // 尾插，如果是第一个数据就设置队头和队尾，否则就尾插到队尾后面
    if (pq->front == NULL)
    {
        pq->front = pq->rear = newnode;
    }
    else
    {
        pq->rear->next = newnode;
        pq->rear = newnode;
    }
    pq->size++;
}

// 出队列
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    // 当只有一个数据的时候，free掉后 front和rear都设置为NULL
    if (pq->front->next == NULL)
    {
        free(pq->front);
        pq->front = pq->rear = NULL;
    }
    else
    {
        QNode *nextnode = pq->front->next;
        free(pq->front);
        pq->front = nextnode;
    }
    pq->size--;
}

// 取队头数据
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->front->data;
}

// 取队尾数据
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->rear->data;
}

// 判断队列是否为空
bool QueueEmpty(Queue *pq)
{
    assert(pq);

    return pq->front == NULL && pq->rear == NULL;
}

// 队列长度
size_t QueueSize(Queue *pq)
{
    assert(pq);

    return pq->size;
}

// 打印队列
void QueuePrint(Queue *pq)
{
    assert(pq);
    while (!QueueEmpty(pq))
    {
        printf("%d->", QueueFront(pq));
        QueuePop(pq);
    }
    printf("NULL");
}

// 思路:
typedef struct
{
    Queue q1; // 队列1
    Queue q2; // 队列2
} MyStack;

MyStack *myStackCreate()
{
    // malloc一个mystack节点
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    // 将2个队列初始化
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);

    return obj;
}

// 将元素 x 压入栈顶。
void myStackPush(MyStack *obj, int x)
{
    // x压到非空的队列里
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

// 移除并返回栈顶元素。
int myStackPop(MyStack *obj)
{
    // 假设q1是空的队列
    Queue *emptyQ = &obj->q1;
    Queue *noemptyQ = &obj->q2;
    // 如果q2是空队列，则交换
    if (QueueEmpty(&obj->q2))
    {
        emptyQ = &obj->q2;
        noemptyQ = &obj->q1;
    }

    // 非空队列的前n-1个数据倒入空队列
    while (QueueSize(noemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(noemptyQ));
        QueuePop(noemptyQ);
    }

    // 取栈顶，也就是剩下的非空队列的最后一个数据，取完pop一下
    int top = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    return top;
}

// 返回栈顶元素。
int myStackTop(MyStack *obj)
{
    // 思路；返回非空队列的队尾，即是栈顶
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack *obj)
{
    // 队列q1和q2都为空 则栈为空
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack *obj)
{
    // free掉obj 和队列q1和q2
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

// https://leetcode.cn/problems/implement-stack-using-queues/