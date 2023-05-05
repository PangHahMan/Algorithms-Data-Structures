/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <algorithm>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 求二叉树高度
    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            int leftHeight = height(root->left) + 1;
            int rightHeight = height(root->right) + 1;
            return leftHeight > rightHeight ? leftHeight : rightHeight;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        // 记录左右高度差
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        // 左右高度大于1直接返回false
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        // 左子树 右子树都是平衡树则返回true
        return isBalanced(root->left) && isBalanced(root->right);
    }
};