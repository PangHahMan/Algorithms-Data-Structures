// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int DataType;
// 动态栈的结构
typedef struct Stack
{
    DataType *a;
    int top;      // 栈顶
    int capacity; // 容量
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

// 初始化
void StackInit(Stack *ps)
{
    assert(ps);
    // 初始化的时候给数组一段空间
    ps->a = (DataType *)malloc(sizeof(DataType) * 4);
    if (ps->a == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    ps->top = -1;     // 栈顶初始化为-1
    ps->capacity = 4; // 容量为4
}

// 销毁栈
void StackDestroy(Stack *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = -1;
    ps->capacity = 0;
}

// 判断是否为空
bool StackEmpty(Stack *ps)
{
    assert(ps);
    // 如果top是-1 则为空 返回真
    return ps->top == -1;
}

// Push
void StackPush(Stack *ps, DataType x)
{
    assert(ps);
    // 扩容
    if (ps->top + 1 == ps->capacity)
    {
        DataType *tmp = (DataType *)realloc(ps->a, ps->capacity * 2 * sizeof(DataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    // 不需要扩容则Push,top初始化为-1 ，先++ 在插入
    ps->top++;
    ps->a[ps->top] = x;
}

// Pop
void StackPop(Stack *ps)
{
    assert(ps);              // 地址不为空
    assert(!StackEmpty(ps)); // 栈不为空
    ps->top--;
}

// 取栈顶
DataType StackTop(Stack *ps)
{
    assert(ps);
    return ps->a[ps->top];
}

// 求栈的长度
size_t StackSize(Stack *ps)
{
    assert(ps);
    return ps->top + 1;
}

// 用栈实现队列
typedef struct
{
    Stack pushst; // 栈1
    Stack popst;  // 栈2
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    StackInit(&obj->pushst);
    StackInit(&obj->popst);

    return obj;
}

// push直接往push栈中进栈
void myQueuePush(MyQueue *obj, int x)
{
    assert(obj);
    StackPush(&obj->pushst, x);
}

// 从队列的开头移除并返回元素
int myQueuePop(MyQueue *obj)
{
    // 将push的栈中数据倒到pop栈中，然后取栈顶，就是队头
    if (StackEmpty(&obj->popst))
    {
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    // 先保存pop栈中的栈顶，也就是队头，在POP掉栈顶
    int peek = StackTop(&obj->popst);
    StackPop(&obj->popst);

    return peek;
}

// 返回队列开头的元素
int myQueuePeek(MyQueue *obj)
{
    // 将push的栈中数据倒到pop栈中，然后取栈顶，就是队头
    if (StackEmpty(&obj->popst))
    {
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }

    return StackTop(&obj->popst);
}

bool myQueueEmpty(MyQueue *obj)
{
    return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}

void myQueueFree(MyQueue *obj)
{
    StackDestroy(&obj->pushst);
    StackEmpty(&obj->popst);
    free(obj);
}

// https://leetcode.cn/problems/implement-queue-using-stacks/