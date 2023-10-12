/* 
给你一个二叉树的根节点root ， 检查它是否轴对称。
示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool _isSymmetric(struct TreeNode *left, struct TreeNode *right) {
        // 两个都为nullptr，对称
        if (left == nullptr && right == nullptr)
            return true;

        // 两个其中一个为nullptr，一个不为nullptr，不对称
        if (left == nullptr || right == nullptr)
            return false;

        // left的左孩子的值和right的值不相等，不对称
        if (left->val != right->val)
            return false;

        // 左子树的左孩子，和右子树的右孩子对比，然后左子树的右孩子和右子树的左孩子在对比
        return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return _isSymmetric(root->left, root->right);
    }
};

//https://leetcode.cn/problems/symmetric-tree/description/