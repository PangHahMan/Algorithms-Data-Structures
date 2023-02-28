#include "BinaryTree.h"
void test1(BinaryTreeNode *n1)
{
	// ǰ�����
	BinaryTreePrevOrder(n1); // 1 2 3 NULL NULL 4 NULL NULL 5 6 NULL NULL 7 NULL NULL
	printf("\n");
	// �������
	BinaryTreeInOrder(n1); // NULL 3 NULL 2 NULL 4 NULL 1 NULL 6 NULL 5 NULL 7 NULL
	printf("\n");
	// �������
	BinaryPostOrder(n1); // NULL NULL 3 NULL NULL 4 2 NULL NULL 6 NULL NULL 7 5 1
	printf("\n");
	// �������
	BinaryTreeLevelOrder(n1); // 1 2 5 3 4 6 7
}

void test2(BinaryTreeNode *n1)
{
	// ��������Ľڵ����
	printf("%d\n", BinaryTreeSize(n1));
	// ���������Ҷ�ӽڵ����
	printf("%d\n", BinaryTreeLeafSize(n1));
	// ��������ĸ߶�
	printf("%d\n", BinaryTreeHeight(n1));
	// ��k��Ҷ�ӽڵ���
	printf("%d\n", BinaryTreeLevelSize(n1, 3));
	// �ж��Ƿ�Ϊ��������
	printf("%d\n", BinaryTreeComplete(n1));
	// ����������ֵΪx�Ľڵ�
	printf("%p\n", BinaryTreeFind(n1, 7));
}

// void test3()
//{
//	//���鴴��������
//	char str[100];
//	scanf("%s", str);
//	int i = 0;
//
//	BinaryTreeNode* root = BinaryTreeCreate(str, &i);
//
//	//ǰ���������
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