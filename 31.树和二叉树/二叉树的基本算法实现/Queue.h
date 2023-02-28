#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "BinaryTree.h"
typedef BinaryTreeNode *QDataType;
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