#include "BinaryTree.h"
void test1(BinaryTreeNode *n1)
{
	// 前序遍历
	BinaryTreePrevOrder(n1); // 1 2 3 NULL NULL 4 NULL NULL 5 6 NULL NULL 7 NULL NULL
	printf("\n");
	// 中序遍历
	BinaryTreeInOrder(n1); // NULL 3 NULL 2 NULL 4 NULL 1 NULL 6 NULL 5 NULL 7 NULL
	printf("\n");
	// 后序遍历
	BinaryPostOrder(n1); // NULL NULL 3 NULL NULL 4 2 NULL NULL 6 NULL NULL 7 5 1
	printf("\n");
	// 层序遍历
	BinaryTreeLevelOrder(n1); // 1 2 5 3 4 6 7
}

void test2(BinaryTreeNode *n1)
{
	// 求二叉树的节点个数
	printf("%d\n", BinaryTreeSize(n1));
	// 求二叉树的叶子节点个数
	printf("%d\n", BinaryTreeLeafSize(n1));
	// 求二叉树的高度
	printf("%d\n", BinaryTreeHeight(n1));
	// 第k层叶子节点数
	printf("%d\n", BinaryTreeLevelSize(n1, 3));
	// 判断是否为满二叉树
	printf("%d\n", BinaryTreeComplete(n1));
	// 二叉树查找值为x的节点
	printf("%p\n", BinaryTreeFind(n1, 7));
}

// void test3()
//{
//	//数组创建二叉树
//	char str[100];
//	scanf("%s", str);
//	int i = 0;
//
//	BinaryTreeNode* root = BinaryTreeCreate(str, &i);
//
//	//前序遍历以下
//	BinaryTreePrevOrder(root);
// }

int main()
{
	BinaryTreeNode *n1 = BuyBinaryTreeNode(1);
	BinaryTreeNode *n2 = BuyBinaryTreeNode(2);
	BinaryTreeNode *n3 = BuyBinaryTreeNode(3);
	BinaryTreeNode *n4 = BuyBinaryTreeNode(4);
	BinaryTreeNode *n5 = BuyBinaryTreeNode(5);
	BinaryTreeNode *n6 = BuyBinaryTreeNode(6);
	BinaryTreeNode *n7 = BuyBinaryTreeNode(7);
	n1->left = n2;
	n1->right = n5;

	n2->left = n3;
	n2->right = n4;

	n5->left = n6;
	n5->right = n7;
	// test1(n1);
	test2(n1);
	// test3();
	return 0;
}