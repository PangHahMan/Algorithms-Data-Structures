// 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
#include <stdbool.h>
#include <stdlib.h>
// 循环队列的结构：使用数组来存储，队头，队尾的下标，一个存储数据的数组。K表示队列长度
typedef struct
{
    int *queue;
    int front;
    int rear;
    int k;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
    // 数组大小要开辟k+1 预留一个空的空间，以方便判断空和满的两种情况
    MyCircularQueue *obj = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    obj->queue = (int *) malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->k = k;

    return obj;
}

// 队列判空front == rear
bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
    assert(obj);
    // 判空的条件是front和rear都为0
    return obj->front == obj->rear;
}

// 队列判满 (rear+1)%(k+1)=front
bool myCircularQueueIsFull(MyCircularQueue *obj) {
    assert(obj);
    // 判满的条件是队列满了，rear指向了最后一个空的数组，+1需要回到front的位置，也就是(rear+1)%(k+1)==front
    return ((obj->rear + 1) % (obj->k + 1)) == obj->front;
}

//求有效长度(rear-front+k+1)%(k+1)
int myCircularQueueLength(MyCircularQueue *obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return 0;

    return (obj->rear - obj->front + obj->k + 1) % (obj->k + 1);
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
    assert(obj);
    // 进队列  如果队列满了，就无法进队列，返回false
    if (myCircularQueueIsFull(obj))
        return false;

    obj->queue[obj->rear++] = value;
    // rear的值溢出，需要重新设置
    obj->rear %= (obj->k + 1);
    /* 也可以这么写
    if (obj->rear > obj->k)
        obj->rear = 0;
    */
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    // front溢出重新设置
    obj->front %= (obj->k + 1);
    /* 也可以这么写
    if (obj->front > obj->k)
        obj->front = 0;
    */
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->queue[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
        return -1;

    // 如果rear == 0 说明rear在最后的位置  也就是k的位置
    if (obj->rear == 0)
        return obj->queue[obj->k];
    else
        return obj->queue[obj->rear - 1];
}

void myCircularQueueFree(MyCircularQueue *obj) {
    free(obj->queue);
    free(obj);
}


// https://leetcode.cn/problems/design-circular-queue/