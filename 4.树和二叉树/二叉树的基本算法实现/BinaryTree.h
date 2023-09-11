#pragma once
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef int BTDataType;
// �������Ľṹ
typedef struct BinaryTreeNode {
    BTDataType data;             // ����ֵ
    struct BinaryTreeNode *left; // ����
    struct BinaryTreeNode *right;// �Һ���
} BinaryTreeNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BinaryTreeNode *BinaryTreeCreate(BTDataType *a, int *pi);
// �������ڵ�
BinaryTreeNode *BuyBinaryTreeNode(BTDataType x);
// ǰ�����
void BinaryTreePrevOrder(BinaryTreeNode *root);
// �������
void BinaryTreeInOrder(BinaryTreeNode *root);
// �������
void BinaryPostOrder(BinaryTreeNode *root);
// ������� - ���ö���
void BinaryTreeLevelOrder(BinaryTreeNode *root);
// ��������ڵ����
int BinaryTreeSize(BinaryTreeNode *root);
// ���������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinaryTreeNode *root);
// ��������ĸ߶�
int BinaryTreeHeight(BinaryTreeNode *root);
// ���k��Ľڵ���� k>=1
int BinaryTreeLevelSize(BinaryTreeNode *root, int k);
// ����������ֵΪx�Ľڵ�
BinaryTreeNode *BinaryTreeFind(BinaryTreeNode *root, BTDataType x);
// ����������
void BinaryTreeDestory(BinaryTreeNode **root);
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BinaryTreeNode *root);