// �����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int DataType;
// ��̬ջ�Ľṹ
typedef struct Stack
{
    DataType *a;
    int top;      // ջ��
    int capacity; // ����
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

// ��ʼ��
void StackInit(Stack *ps)
{
    assert(ps);
    // ��ʼ����ʱ�������һ�οռ�
    ps->a = (DataType *)malloc(sizeof(DataType) * 4);
    if (ps->a == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    ps->top = -1;     // ջ����ʼ��Ϊ-1
    ps->capacity = 4; // ����Ϊ4
}

// ����ջ
void StackDestroy(Stack *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = -1;
    ps->capacity = 0;
}

// �ж��Ƿ�Ϊ��
bool StackEmpty(Stack *ps)
{
    assert(ps);
    // ���top��-1 ��Ϊ�� ������
    return ps->top == -1;
}

// Push
void StackPush(Stack *ps, DataType x)
{
    assert(ps);
    // ����
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
    // ����Ҫ������Push,top��ʼ��Ϊ-1 ����++ �ڲ���
    ps->top++;
    ps->a[ps->top] = x;
}

// Pop
void StackPop(Stack *ps)
{
    assert(ps);              // ��ַ��Ϊ��
    assert(!StackEmpty(ps)); // ջ��Ϊ��
    ps->top--;
}

// ȡջ��
DataType StackTop(Stack *ps)
{
    assert(ps);
    return ps->a[ps->top];
}

// ��ջ�ĳ���
size_t StackSize(Stack *ps)
{
    assert(ps);
    return ps->top + 1;
}

// ��ջʵ�ֶ���
typedef struct
{
    Stack pushst; // ջ1
    Stack popst;  // ջ2
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    StackInit(&obj->pushst);
    StackInit(&obj->popst);

    return obj;
}

// pushֱ����pushջ�н�ջ
void myQueuePush(MyQueue *obj, int x)
{
    assert(obj);
    StackPush(&obj->pushst, x);
}

// �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int myQueuePop(MyQueue *obj)
{
    // ��push��ջ�����ݵ���popջ�У�Ȼ��ȡջ�������Ƕ�ͷ
    if (StackEmpty(&obj->popst))
    {
        while (!StackEmpty(&obj->pushst))
        {
            StackPush(&obj->popst, StackTop(&obj->pushst));
            StackPop(&obj->pushst);
        }
    }
    // �ȱ���popջ�е�ջ����Ҳ���Ƕ�ͷ����POP��ջ��
    int peek = StackTop(&obj->popst);
    StackPop(&obj->popst);

    return peek;
}

// ���ض��п�ͷ��Ԫ��
int myQueuePeek(MyQueue *obj)
{
    // ��push��ջ�����ݵ���popջ�У�Ȼ��ȡջ�������Ƕ�ͷ
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