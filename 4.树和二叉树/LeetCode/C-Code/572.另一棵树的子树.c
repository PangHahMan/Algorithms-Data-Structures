#include <stdbool.h>
#include <stdlib.h>
// �������ö�����root��subRoot ������root���Ƿ������subRoot������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true������,����false ��
// ������tree��һ����������tree��ĳ���ڵ������ڵ�����к���ڵ㡣treeҲ���Կ����������һ��������

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;

    if (root == NULL || subRoot == NULL)
        return false;

    if (root->val != subRoot->val)
        return false;

    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
    // �ݹ�ÿһ���������ж�ÿһ�������Ƿ��subRoot����ͬ�Ķ�����
    // ���root==null������false
    if (root == NULL)
        return false;

    // ���root��subRoot��ͬ���򷵻�true
    if (isSameTree(root, subRoot))
        return true;

    // �ݹ�ÿһ��������ֻҪ��һ��������subRoot��ȣ���˵��subRoot��root������
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// https://leetcode.cn/problems/subtree-of-another-tree/