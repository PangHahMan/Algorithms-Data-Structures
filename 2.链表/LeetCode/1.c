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

// 申请节点
ListNode *BuyListNode(DataType x);
// 链表初始化
ListNode *ListInit();
// 链表打印
void ListPrint(ListNode *phead);
// 尾插
void ListPushBack(ListNode *phead, DataType x);
// 尾删
void ListPopBack(ListNode *phead);
// 头插
void ListPushFront(ListNode *phead, DataType x);
// 头删
void ListPopFront(ListNode *phead);
// 查找x的位置
ListNode *ListFind(ListNode *phead, DataType x);
// 在pos之前插入x
void ListInsert(ListNode *pos, DataType x);
// 删除pos位置
void ListErase(ListNode *pos);
// 判断链表是否为空
bool ListEmpty(ListNode *phead);
// 求链表长度
size_t ListSize(ListNode *phead);
// 链表销毁
void ListDestroy(ListNode *phead);
