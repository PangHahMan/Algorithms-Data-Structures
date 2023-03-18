// ����������ĸ��ڵ�root ���������ڵ�ֵ��ǰ�������
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int TreeSize(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void Preoder(struct TreeNode *root, int *a, int *pi)
{
    if (root == NULL)
    {
        return;
    }
    //��������ֵ���ŵ�������
    a[(*pi)++] = root->val;
     Preoder(root->left, a, pi);
    Preoder(root->right, a, pi);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    // ���������size������returnSize
    *returnSize = TreeSize(root);
    // ����һ�����飬�����洢��������ֵ������������ڷ��ظ�������
    int *a = (int *)malloc(*returnSize * sizeof(int));
    int i = 0;
    //�����i���봫��ַ����Ϊ�ݹ鴴��i�Ĺ����У�i�ڶ��лᱻ�ظ�����
    Preoder(root, a, &i);
    return a;
}

// https://leetcode.cn/problems/binary-tree-preorder-traversal/