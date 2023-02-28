#include "Stack.h"

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