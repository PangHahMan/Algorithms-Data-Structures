// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
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
    // 两个都为NULL，对称
    if (left == NULL && right == NULL)
        return true;

    // 两个其中一个为NULL，一个不为NULL，不对称
    if (left == NULL || right == NULL)
        return false;

    // left的左孩子的值和right的值不相等，不对称
    if (left->val != right->val)
        return false;

    // 左子树的左孩子，和右子树的右孩子对比，然后左子树的右孩子和右子树的左孩子在对比
    return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
    // 判断一个树的两个子树是否相等- 需要在设置一个函数
    // 如果root==NULL ，则返回真
    if (root == NULL)
        return true;

    // 递归左子树和右子树判断左右子树关系
    return _isSymmetric(root->left, root->right);
}

// https://leetcode.cn/problems/symmetric-tree/