#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int SLDataType;
typedef struct SListNode {
    SLDataType data;       //���������ڴ洢�ý�������
    struct SListNode *next;//ָ�������ڴ����һ�����ĵ�ַ
} SListNode;

// ��̬����һ���ڵ�
SListNode *BuySListNode(SLDataType x);
// ����n�����
SListNode *SListCreate(int n);
// ��ӡ
void SListPrint(SListNode *plist);
// ������β��
void SListPushBack(SListNode **pplist, SLDataType x);
// �������ͷ��
void SListPushFront(SListNode **pplist, SLDataType x);
// �������βɾ
void SListPopBack(SListNode **pplist);
// ������ͷɾ
void SListPopFront(SListNode **pplist);
// ���������
SListNode *SListFind(SListNode *plist, SLDataType x);
// x���뵽posλ��֮��
void SListInsertAfter(SListNode *pos, SLDataType x);
// x���뵽posλ��֮ǰ
void SListInsert(SListNode **pplist, SListNode *pos, SLDataType x);
// ɾ��pos֮����
void SListEraseAfter(SListNode *pos);
// ɾ��posλ�ý��
void SListErase(SListNode **pplist, SListNode *pos);
// �����������1
void SListDestroy(SListNode **pplist);
