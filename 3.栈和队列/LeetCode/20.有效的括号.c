// ����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// ˼·������ջ��ʵ��
typedef char DataType;
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

bool isValid(char *s)
{
    Stack st;
    // ��ʼ��ջ
    StackInit(&st);
    // ѭ����ʼ�ж�
    while (*s != NULL)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            // ����������ž���ջ
            StackPush(&st, *s);
            s++;
        }
        else
        {
            // ���ջ��û�����ݣ���һ�����������ţ�˵����ƥ��
            if (StackEmpty(&st))
            {
                return false;
            }
            // ȡջ����top�����Ƚ�
            char top = StackTop(&st);

            if (top == '(' && *s == ')' ||
                top == '{' && *s == '}' ||
                top == '[' && *s == ']')
            {
                // ƥ��ɹ�����Pop��
                StackPop(&st);
                s++;
            }
            else
            {
                return false;
            }
        }
    }
    // �ж�ջ�Ƿ�Ϊ��  ���ƥ��Ļ������е�ջ�����ݶ���Pop��������Ϊ�� Ϊ��
    bool ret = StackEmpty(&st);
    return ret;
}

// https://leetcode.cn/problems/valid-parentheses/