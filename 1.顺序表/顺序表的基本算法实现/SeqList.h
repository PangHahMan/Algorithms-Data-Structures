#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList // 顺序表的结构(动态)
{
    SLDataType* a;
    int size;
    int capacity;
} SeqList;

// 对数据的管理:增删查改
void SeqListInit(SeqList* ps);                    // 顺序表的初始化
void SeqListDestroy(SeqList* ps);                 // 顺序表的销毁
void SeqListPrint(SeqList* ps);                   // 顺序表的打印
void Check_Capacity(SeqList* ps);                 // 检查是否需要扩容
void SeqListPushBack(SeqList* ps, SLDataType x);  // 顺序表的尾插
void SeqListPushFront(SeqList* ps, SLDataType x); // 顺序表的头插
void SeqListPopFront(SeqList* ps);                // 顺序表的头删
void SeqListPopBack(SeqList* ps);                 // 顺序表的尾删

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);