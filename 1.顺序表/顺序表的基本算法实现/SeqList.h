#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
typedef struct SeqList // ˳���Ľṹ(��̬)
{
    SLDataType* a;
    int size;
    int capacity;
} SeqList;

// �����ݵĹ���:��ɾ���
void SeqListInit(SeqList* ps);                    // ˳���ĳ�ʼ��
void SeqListDestroy(SeqList* ps);                 // ˳��������
void SeqListPrint(SeqList* ps);                   // ˳���Ĵ�ӡ
void Check_Capacity(SeqList* ps);                 // ����Ƿ���Ҫ����
void SeqListPushBack(SeqList* ps, SLDataType x);  // ˳����β��
void SeqListPushFront(SeqList* ps, SLDataType x); // ˳����ͷ��
void SeqListPopFront(SeqList* ps);                // ˳����ͷɾ
void SeqListPopBack(SeqList* ps);                 // ˳����βɾ

// ˳������
int SeqListFind(SeqList* ps, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);