#include "Queue.h"

// ���еĳ�ʼ��
void QueueInit(Queue *pq) {
    assert(pq);
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

// ���е�����
void QueueDestroy(Queue *pq) {
    assert(pq);
	//���ն�ͷ
    QNode *cur = pq->front;
    //ѭ��������������
	while (cur) {
        QNode *nextnode = cur->next;
        free(cur);
        cur = nextnode;
    }
	//��ʼ��
    pq->front = pq->rear = NULL;
    pq->size = 0;
}

// ������
void QueuePush(Queue *pq, QDataType x) {
    assert(pq);
    QNode *newnode = (QNode *) malloc(sizeof(QNode));  //�����½ڵ�
    if (newnode == NULL) {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    // β�壬����ǵ�һ�����ݾ����ö�ͷ�Ͷ�β�������β�嵽��β����
    if (pq->front == NULL) {
        pq->front = pq->rear = newnode;
    } else {
        pq->rear->next = newnode;
        pq->rear = newnode;
    }
    pq->size++;
}

// ������
void QueuePop(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    // ��ֻ��һ�����ݵ�ʱ��free���� front��rear������ΪNULL
    if (pq->front->next == NULL) {
        free(pq->front);
        pq->front = pq->rear = NULL;
    } else {
        QNode *nextnode = pq->front->next;
        free(pq->front);
        pq->front = nextnode;
    }
    pq->size--;
}

// ȡ��ͷ����
QDataType QueueFront(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->front->data;
}

// ȡ��β����
QDataType QueueBack(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->rear->data;
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *pq) {
    assert(pq);

    return pq->front == NULL && pq->rear == NULL;
}

// ���г���
size_t QueueSize(Queue *pq) {
    assert(pq);

    return pq->size;
}

// ��ӡ����
void QueuePrint(Queue *pq) {
    assert(pq);
    while (!QueueEmpty(pq)) {
        printf("%d->", QueueFront(pq));
        QueuePop(pq);
    }
    printf("NULL");
}