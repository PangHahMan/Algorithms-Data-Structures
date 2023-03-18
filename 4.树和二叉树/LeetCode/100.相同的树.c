// 给你两棵二叉树的根节点p和q ，编写一个函数来检验这两棵树是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    // 当p和q都为NULL的时候，返回真
    if (p == NULL && q == NULL)
        return true;

    // 其中一个为NULL ，返回假  这里两个为NULL 上面已经判断了，所以可以这么写
    if (p == NULL || q == NULL)
        return false;

    // 两棵树左右子树的值都相同，这个判断顺序必须在最后，因为p和q可能为NULL，会发生空指针解引用
    // 如果放前面要加上p&&q
    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// https://leetcode.cn/problems/same-tree/