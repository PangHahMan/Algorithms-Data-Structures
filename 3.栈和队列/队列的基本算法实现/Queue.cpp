#include "Queue.h"

// 队列的初始化
void QueueInit(Queue *pq) {
    assert(pq);
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

// 队列的销毁
void QueueDestroy(Queue *pq) {
    assert(pq);
	//接收队头
    QNode *cur = pq->front;
    //循环遍历队列销毁
	while (cur) {
        QNode *nextnode = cur->next;
        free(cur);
        cur = nextnode;
    }
	//初始化
    pq->front = pq->rear = NULL;
    pq->size = 0;
}

// 进队列
void QueuePush(Queue *pq, QDataType x) {
    assert(pq);
    QNode *newnode = (QNode *) malloc(sizeof(QNode));  //申请新节点
    if (newnode == NULL) {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    // 尾插，如果是第一个数据就设置队头和队尾，否则就尾插到队尾后面
    if (pq->front == NULL) {
        pq->front = pq->rear = newnode;
    } else {
        pq->rear->next = newnode;
        pq->rear = newnode;
    }
    pq->size++;
}

// 出队列
void QueuePop(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    // 当只有一个数据的时候，free掉后 front和rear都设置为NULL
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

// 取队头数据
QDataType QueueFront(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->front->data;
}

// 取队尾数据
QDataType QueueBack(Queue *pq) {
    assert(pq);
    assert(!QueueEmpty(pq));

    return pq->rear->data;
}

// 判断队列是否为空
bool QueueEmpty(Queue *pq) {
    assert(pq);

    return pq->front == NULL && pq->rear == NULL;
}

// 队列长度
size_t QueueSize(Queue *pq) {
    assert(pq);

    return pq->size;
}

// 打印队列
void QueuePrint(Queue *pq) {
    assert(pq);
    while (!QueueEmpty(pq)) {
        printf("%d->", QueueFront(pq));
        QueuePop(pq);
    }
    printf("NULL");
}