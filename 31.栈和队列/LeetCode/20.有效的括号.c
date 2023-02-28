// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// 思路；利用栈来实现
typedef char DataType;
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

bool isValid(char *s)
{
    Stack st;
    // 初始化栈
    StackInit(&st);
    // 循环开始判断
    while (*s != NULL)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            // 如果是左括号就入栈
            StackPush(&st, *s);
            s++;
        }
        else
        {
            // 如果栈中没有数据，第一个就是右括号，说明不匹配
            if (StackEmpty(&st))
            {
                return false;
            }
            // 取栈顶给top，作比较
            char top = StackTop(&st);

            if (top == '(' && *s == ')' ||
                top == '{' && *s == '}' ||
                top == '[' && *s == ']')
            {
                // 匹配成功可以Pop了
                StackPop(&st);
                s++;
            }
            else
            {
                return false;
            }
        }
    }
    // 判断栈是否为空  如果匹配的话，所有的栈中数据都被Pop出来，则为空 为真
    bool ret = StackEmpty(&st);
    return ret;
}

// https://leetcode.cn/problems/valid-parentheses/