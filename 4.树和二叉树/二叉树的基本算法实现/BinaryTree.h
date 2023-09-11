#pragma once
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef int BTDataType;
// 二叉树的结构
typedef struct BinaryTreeNode {
    BTDataType data;             // 树的值
    struct BinaryTreeNode *left; // 左孩子
    struct BinaryTreeNode *right;// 右孩子
} BinaryTreeNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BinaryTreeNode *BinaryTreeCreate(BTDataType *a, int *pi);
// 申请树节点
BinaryTreeNode *BuyBinaryTreeNode(BTDataType x);
// 前序遍历
void BinaryTreePrevOrder(BinaryTreeNode *root);
// 中序遍历
void BinaryTreeInOrder(BinaryTreeNode *root);
// 后序遍历
void BinaryPostOrder(BinaryTreeNode *root);
// 层序遍历 - 利用队列
void BinaryTreeLevelOrder(BinaryTreeNode *root);
// 求二叉树节点个数
int BinaryTreeSize(BinaryTreeNode *root);
// 求二叉树的叶子节点个数
int BinaryTreeLeafSize(BinaryTreeNode *root);
// 求二叉树的高度
int BinaryTreeHeight(BinaryTreeNode *root);
// 求第k层的节点个数 k>=1
int BinaryTreeLevelSize(BinaryTreeNode *root, int k);
// 二叉树查找值为x的节点
BinaryTreeNode *BinaryTreeFind(BinaryTreeNode *root, BTDataType x);
// 二叉树销毁
void BinaryTreeDestory(BinaryTreeNode **root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BinaryTreeNode *root);