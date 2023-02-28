// �����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef int QDataType;
// �������ͷ�Ͷ�β�Ľṹ
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode *next;
} QNode;

// ���еĽṹ
typedef struct Queue
{
    QNode *front; // ��ͷ
    QNode *rear;  // ��β
    size_t size;  // ���г���
} Queue;

// ���еĳ�ʼ��
void QueueInit(Queue *pq);
// ���е�����
void QueueDestroy(Queue *pq);
// ������
void QueuePush(Queue *pq, QDataType x);
// ������
void QueuePop(Queue *pq);
// ȡ��ͷ����
QDataType QueueFront(Queue *pq);
// ȡ��β����
QDataType QueueBack(Queue *pq);
// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *pq);
// ���г���
size_t QueueSize(Queue *pq);
// ��ӡ����
void QueuePrint(Queue *pq);

// ���еĳ�ʼ��
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

// ���е�����
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

// ������
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
    // β�壬����ǵ�һ�����ݾ����ö�ͷ�Ͷ�β�������β�嵽��β����
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

// ������
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    // ��ֻ��һ�����ݵ�ʱ��free���� front��rear������ΪNULL
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

// ȡ��ͷ����
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->front->data;
}

// ȡ��β����
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->rear->data;
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *pq)
{
    assert(pq);

    return pq->front == NULL && pq->rear == NULL;
}

// ���г���
size_t QueueSize(Queue *pq)
{
    assert(pq);

    return pq->size;
}

// ��ӡ����
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

// ˼·:
typedef struct
{
    Queue q1; // ����1
    Queue q2; // ����2
} MyStack;

MyStack *myStackCreate()
{
    // mallocһ��mystack�ڵ�
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    // ��2�����г�ʼ��
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);

    return obj;
}

// ��Ԫ�� x ѹ��ջ����
void myStackPush(MyStack *obj, int x)
{
    // xѹ���ǿյĶ�����
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

// �Ƴ�������ջ��Ԫ�ء�
int myStackPop(MyStack *obj)
{
    // ����q1�ǿյĶ���
    Queue *emptyQ = &obj->q1;
    Queue *noemptyQ = &obj->q2;
    // ���q2�ǿն��У��򽻻�
    if (QueueEmpty(&obj->q2))
    {
        emptyQ = &obj->q2;
        noemptyQ = &obj->q1;
    }

    // �ǿն��е�ǰn-1�����ݵ���ն���
    while (QueueSize(noemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(noemptyQ));
        QueuePop(noemptyQ);
    }

    // ȡջ����Ҳ����ʣ�µķǿն��е����һ�����ݣ�ȡ��popһ��
    int top = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    return top;
}

// ����ջ��Ԫ�ء�
int myStackTop(MyStack *obj)
{
    // ˼·�����طǿն��еĶ�β������ջ��
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
    // ����q1��q2��Ϊ�� ��ջΪ��
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack *obj)
{
    // free��obj �Ͷ���q1��q2
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

// https://leetcode.cn/problems/implement-stack-using-queues/