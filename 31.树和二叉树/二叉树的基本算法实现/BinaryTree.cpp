#include "BinaryTree.h"
#include "Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BinaryTreeNode *BinaryTreeCreate(BTDataType *a, int *pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->data = a[(*pi)++];

	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}

// �������ڵ�
BinaryTreeNode *BuyBinaryTreeNode(BTDataType x)
{
	BinaryTreeNode *newnode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// ǰ�����
void BinaryTreePrevOrder(BinaryTreeNode *root)
{
	// ǰ����� ������������������
	// ���rootΪ�գ��ݹ����
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������
void BinaryTreeInOrder(BinaryTreeNode *root)
{
	// ������� - ������������������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

// �������
void BinaryPostOrder(BinaryTreeNode *root)
{
	// ������� - ������������������
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryPostOrder(root->left);
	BinaryPostOrder(root->right);
	printf("%d ", root->data);
}

// ��������ڵ����
int BinaryTreeSize(BinaryTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ���������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinaryTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������ĸ߶�
int BinaryTreeHeight(BinaryTreeNode *root)
{
	// ���������ĸ߶ȣ��������ĸ߶�
	// ȡ����
	if (root == NULL)
	{
		return 0;
	}
	int leftHeight = BinaryTreeHeight(root->left);
	int rightHeight = BinaryTreeHeight(root->right);

	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// ���k��Ľڵ���� k>=1
int BinaryTreeLevelSize(BinaryTreeNode *root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelSize(root->left, k - 1) + BinaryTreeLevelSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BinaryTreeNode *BinaryTreeFind(BinaryTreeNode *root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	// �������ݹ�Ľڵ㱣�浽leftTree��,���leftTree��ΪNULL����return leftTree
	BinaryTreeNode *leftTree = BinaryTreeFind(root->left, x);
	if (leftTree)
	{
		return leftTree;
	}

	// �������ݹ�Ľڵ㱣�浽rightTree��,���rightTree��ΪNULL����return rightTree
	BinaryTreeNode *rightTree = BinaryTreeFind(root->right, x);
	if (rightTree)
	{
		return rightTree;
	}

	// �Ҳ���������NULL
	return NULL;
}

// ����������
void BinaryTreeDestory(BinaryTreeNode **root)
{
	if (*root == NULL)
	{
		return;
	}
	// ����������٣���Ҫ����ͷ�
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}

// ������� - ���ö���
void BinaryTreeLevelOrder(BinaryTreeNode *root)
{
	// ����һ�����У������������ݣ�ȡ��ͷ��Ȼ���������������һ��������һ��������������
	Queue q;
	QueueInit(&q);
	if (root)
	{
		// root��ΪNULL���������
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		// ȡ��ͷ����ӡ
		BinaryTreeNode *front = QueueFront(&q);
		printf("%d ", front->data);

		// ȡ��POP
		QueuePop(&q);
		// ȡ��ͷ������һ��,
		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BinaryTreeNode *root)
{
	// �����ߣ��ߵ���һ��Ϊ�յ�ʱ�򣬾�����ȥ���������������������Ľڵ㶼Ӧ��Ϊ��
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BinaryTreeNode *front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	// �������Ժ��������ȫ�ǿգ�������ȫ������
	while (!QueueEmpty(&q))
	{
		BinaryTreeNode *front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}