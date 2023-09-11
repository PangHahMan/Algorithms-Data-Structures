#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int HPDataType;
// �ѵĽṹ - ˳���
typedef struct Heap {
    HPDataType *a;
    int size;
    int capacity;
} Heap;

// �ѵĴ��� - �����㷨
void HeapCreate(Heap *php, HPDataType *a, int n);
// �ѵĳ�ʼ��
void HeapInit(Heap *php);
// �ѵĴ�ӡ
void HeapPrint(Heap *php);
// �ѵ�����
void HeapDestroy(Heap *php);
// ���ϵ��� - ���
void AdjustUp(HPDataType *a, int child);
// ���µ��� - ���
void AdjustDown(HPDataType *a, int n, int parent);
// �ѵĲ���
void HeapPush(Heap *php, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap *php);
// ȡ�Ѷ�
HPDataType HeapTop(Heap *php);
// ��ѵĳ���
size_t HeapSize(Heap *php);
// �ѵ��п�
bool HeapEmpty(Heap *php);
// ����
void Swap(HPDataType *p1, HPDataType *p2);