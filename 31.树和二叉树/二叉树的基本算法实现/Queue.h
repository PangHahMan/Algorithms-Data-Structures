#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "BinaryTree.h"
typedef BinaryTreeNode *QDataType;
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