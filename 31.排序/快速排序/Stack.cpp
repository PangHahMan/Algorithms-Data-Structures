#include "Stack.h"

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