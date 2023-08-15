// ����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    // ���root==NULL  �ͷ���NULL
    if (root == NULL)
    {
        return NULL;
    }

    //�ݹ��������������� ���������������Ӻ��Һ��ӽ���
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
}

// https://leetcode.cn/problems/invert-binary-tree/