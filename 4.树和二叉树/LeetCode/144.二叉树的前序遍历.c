// 给你二叉树的根节点root ，返回它节点值的前序遍历。
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
    //二叉树的值，放到数组中
    a[(*pi)++] = root->val;
     Preoder(root->left, a, pi);
    Preoder(root->right, a, pi);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    // 求二叉树的size个数给returnSize
    *returnSize = TreeSize(root);
    // 创建一个数组，用来存储二叉树的值，这个数组用于返回给主函数
    int *a = (int *)malloc(*returnSize * sizeof(int));
    int i = 0;
    //这里的i必须传地址，因为递归创建i的过程中，i在堆中会被重复利用
    Preoder(root, a, &i);
    return a;
}

// https://leetcode.cn/problems/binary-tree-preorder-traversal/