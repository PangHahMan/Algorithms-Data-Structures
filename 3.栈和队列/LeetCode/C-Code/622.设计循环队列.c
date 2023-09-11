// ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
#include <stdbool.h>
#include <stdlib.h>
// ѭ�����еĽṹ��ʹ���������洢����ͷ����β���±꣬һ���洢���ݵ����顣K��ʾ���г���
typedef struct
{
    int *queue;
    int front;
    int rear;
    int k;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
    // �����СҪ����k+1 Ԥ��һ���յĿռ䣬�Է����жϿպ������������
    MyCircularQueue *obj = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    obj->queue = (int *) malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->k = k;

    return obj;
}

// �����п�front == rear
bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
    assert(obj);
    // �пյ�������front��rear��Ϊ0
    return obj->front == obj->rear;
}

// �������� (rear+1)%(k+1)=front
bool myCircularQueueIsFull(MyCircularQueue *obj) {
    assert(obj);
    // �����������Ƕ������ˣ�rearָ�������һ���յ����飬+1��Ҫ�ص�front��λ�ã�Ҳ����(rear+1)%(k+1)==front
    return ((obj->rear + 1) % (obj->k + 1)) == obj->front;
}

//����Ч����(rear-front+k+1)%(k+1)
int myCircularQueueLength(MyCircularQueue *obj) {
    assert(obj);

    if (myCircularQueueIsEmpty(obj))
        return 0;

    return (obj->rear - obj->front + obj->k + 1) % (obj->k + 1);
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
    assert(obj);
    // ������  ����������ˣ����޷������У�����false
    if (myCircularQueueIsFull(obj))
        return false;

    obj->queue[obj->rear++] = value;
    // rear��ֵ�������Ҫ��������
    obj->rear %= (obj->k + 1);
    /* Ҳ������ôд
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
    // front�����������
    obj->front %= (obj->k + 1);
    /* Ҳ������ôд
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

    // ���rear == 0 ˵��rear������λ��  Ҳ����k��λ��
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