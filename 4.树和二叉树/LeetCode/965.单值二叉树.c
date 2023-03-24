#include <stdlib.h>
#include <stdbool.h>
// 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
// 只有给定的树是单值二叉树时，才返回true；否则返回false。
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode *root)
{
    // 思路  二叉树的左子树和根和右子树的值都相等，递归结束条件是root为NULL
    // 1.走左子树的递归，如果遇到不相等的 直接返回false
    // 2.走右子树的递归，如果遇到不相等的 直接返回false
    // 3.递归条件是走到NULL 在返回结果，走到NULL 就返回true
    if (root == NULL)
    {
        return true;
    }
    // 这里要注意root->left和root->right 不能为NULL
    if (root->left && root->val != root->left->val)
        return false;

    if (root->right && root->val != root->right->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

// https://leetcode.cn/problems/univalued-binary-tree/