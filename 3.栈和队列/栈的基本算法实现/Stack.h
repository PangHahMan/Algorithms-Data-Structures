#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
// ��̬ջ�Ľṹ
typedef struct Stack {
    DataType *a;
    int top;     // ջ��
    int capacity;// ����
} Stack;

// ��ʼ��ջ
void StackInit(Stack *ps);
// ����ջ
void StackDestroy(Stack *ps);
// �ж��Ƿ�Ϊ��
bool StackEmpty(Stack *ps);
// Push
void StackPush(Stack *ps, DataType x);
// Pop
void StackPop(Stack *ps);
// ȡջ��
DataType StackTop(Stack *ps);
// ��ջ�ĳ���
size_t StackSize(Stack *ps);
