#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int DataType;
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

// ����ڵ�
ListNode *BuyListNode(DataType x);
// �����ʼ��
ListNode *ListInit();
// �����ӡ
void ListPrint(ListNode *phead);
// β��
void ListPushBack(ListNode *phead, DataType x);
// βɾ
void ListPopBack(ListNode *phead);
// ͷ��
void ListPushFront(ListNode *phead, DataType x);
// ͷɾ
void ListPopFront(ListNode *phead);
// ����x��λ��
ListNode *ListFind(ListNode *phead, DataType x);
// ��pos֮ǰ����x
void ListInsert(ListNode *pos, DataType x);
// ɾ��posλ��
void ListErase(ListNode *pos);
// �ж������Ƿ�Ϊ��
bool ListEmpty(ListNode *phead);
// ��������
size_t ListSize(ListNode *phead);
// ��������
void ListDestroy(ListNode *phead);
