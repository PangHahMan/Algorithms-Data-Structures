#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int HPDataType;
// 堆的结构 - 顺序表
typedef struct Heap {
    HPDataType *a;
    int size;
    int capacity;
} Heap;

// 堆的创建 - 建堆算法
void HeapCreate(Heap *php, HPDataType *a, int n);
// 堆的初始化
void HeapInit(Heap *php);
// 堆的打印
void HeapPrint(Heap *php);
// 堆的销毁
void HeapDestroy(Heap *php);
// 向上调整 - 大堆
void AdjustUp(HPDataType *a, int child);
// 向下调整 - 大堆
void AdjustDown(HPDataType *a, int n, int parent);
// 堆的插入
void HeapPush(Heap *php, HPDataType x);
// 堆的删除
void HeapPop(Heap *php);
// 取堆顶
HPDataType HeapTop(Heap *php);
// 求堆的长度
size_t HeapSize(Heap *php);
// 堆的判空
bool HeapEmpty(Heap *php);
// 交换
void Swap(HPDataType *p1, HPDataType *p2);