// 给定一个二叉树，找出其最大深度。
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。

#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    // 二叉树的最大深度，也就是说找左子树和右子树中最大的那个子树的深度
    // 递归条件是找到NULL为止
    if (root == NULL)
    {
        return 0;
    }

    //如果跟的左右子树都为NULL 就返回1
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // 递归左子树
    int depthleft = maxDepth(root->left);
    int depthright = maxDepth(root->right);
    return depthleft > depthright ? depthleft + 1 : depthright + 1;
}

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/