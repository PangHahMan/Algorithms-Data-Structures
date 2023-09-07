#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
// 动态栈的结构
typedef struct Stack {
    DataType *a;
    int top;     // 栈顶
    int capacity;// 容量
} Stack;

// 初始化栈
void StackInit(Stack *ps);
// 销毁栈
void StackDestroy(Stack *ps);
// 判断是否为空
bool StackEmpty(Stack *ps);
// Push
void StackPush(Stack *ps, DataType x);
// Pop
void StackPop(Stack *ps);
// 取栈顶
DataType StackTop(Stack *ps);
// 求栈的长度
size_t StackSize(Stack *ps);
