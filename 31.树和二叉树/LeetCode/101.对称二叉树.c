// ����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
#include <stdbool.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool _isSymmetric(struct TreeNode *left, struct TreeNode *right)
{
    // ������ΪNULL���Գ�
    if (left == NULL && right == NULL)
        return true;

    // ��������һ��ΪNULL��һ����ΪNULL�����Գ�
    if (left == NULL || right == NULL)
        return false;

    // left�����ӵ�ֵ��right��ֵ����ȣ����Գ�
    if (left->val != right->val)
        return false;

    // �����������ӣ������������Һ��ӶԱȣ�Ȼ�����������Һ��Ӻ��������������ڶԱ�
    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    // �ж�һ���������������Ƿ����- ��Ҫ������һ������
    // ���root==NULL ���򷵻���
    if (root == NULL)
        return true;

    // �ݹ����������������ж�����������ϵ
    return _isSymmetric(root->left, root->right);
}

// https://leetcode.cn/problems/symmetric-tree/