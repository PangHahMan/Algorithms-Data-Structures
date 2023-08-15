// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    // 如果root==NULL  就返回NULL
    if (root == NULL)
    {
        return NULL;
    }

    //递归左子树和右子树 ，将左子树的左孩子和右孩子交换
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
}

// https://leetcode.cn/problems/invert-binary-tree/