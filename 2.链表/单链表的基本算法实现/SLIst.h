#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;
typedef struct SListNode {
    SLDataType data;       //数据域：用于存储该结点的数据
    struct SListNode *next;//指针域：用于存放下一个结点的地址
} SListNode;

// 动态申请一个节点
SListNode *BuySListNode(SLDataType x);
// 创建n个结点
SListNode *SListCreate(int n);
// 打印
void SListPrint(SListNode *plist);
// 单链表尾插
void SListPushBack(SListNode **pplist, SLDataType x);
// 单链表的头插
void SListPushFront(SListNode **pplist, SLDataType x);
// 单链表的尾删
void SListPopBack(SListNode **pplist);
// 单链表头删
void SListPopFront(SListNode **pplist);
// 单链表查找
SListNode *SListFind(SListNode *plist, SLDataType x);
// x插入到pos位置之后
void SListInsertAfter(SListNode *pos, SLDataType x);
// x插入到pos位置之前
void SListInsert(SListNode **pplist, SListNode *pos, SLDataType x);
// 删除pos之后结点
void SListEraseAfter(SListNode *pos);
// 删除pos位置结点
void SListErase(SListNode **pplist, SListNode *pos);
// 单链表的销毁1
void SListDestroy(SListNode **pplist);
