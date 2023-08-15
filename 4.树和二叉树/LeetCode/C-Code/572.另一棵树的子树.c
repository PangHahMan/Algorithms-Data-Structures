#include <stdbool.h>
#include <stdlib.h>
// 给你两棵二叉树root和subRoot 。检验root中是否包含和subRoot具有相同结构和节点值的子树。如果存在，返回 true；否则,返回false 。
// 二叉树tree的一棵子树包括tree的某个节点和这个节点的所有后代节点。tree也可以看做它自身的一棵子树。

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
    // 递归每一个子树，判断每一个子树是否和subRoot是相同的二叉树
    // 如果root==null，返回false
    if (root == NULL)
        return false;

    // 如果root和subRoot相同，则返回true
    if (isSameTree(root, subRoot))
        return true;

    // 递归每一个子树，只要有一个子树和subRoot相等，就说明subRoot是root的子树
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// https://leetcode.cn/problems/subtree-of-another-tree/